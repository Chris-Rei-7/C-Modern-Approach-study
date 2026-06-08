//静默猎手现有21张牌，其中有一张华丽收场，2张杂技+，一张早有准备+，一张本能反应+，一张逃脱计划，有3点费用，求在没有计划妥当的情况下能在第一回合打出华丽收场的概率。
#include <stdio.h>

// 牌的代号：0=废牌, 1=杂技, 2=早有准备, 3=逃脱计划, 4=本能反应, 5=华丽收场
int deck[21]; 

// 前置声明弃牌判定函数
int try_prep_discards(int drawn, int hA, int hP, int hE, int hR, int hGF, int hD, int energy);
int try_acro_discards(int drawn, int hA, int hP, int hE, int hR, int hGF, int hD, int energy);

// 核心 DFS 状态机：摒弃所有 if-else if 优先级，全部改为平行 if 穷举
int solve_state(int drawn, int hA, int hP, int hE, int hR, int hGF, int hD, int energy) {
    // 胜利条件：牌库抽空，且华丽收场安稳地在手中！
    if (drawn >= 21) {
        return hGF > 0; 
    }

    int cur_sz = hA + hP + hE + hR + hGF + hD;

    // ================= 平行宇宙 1：打出一张废牌腾空间 =================
    if (hD > 0 && energy > 0) {
        // 如果这条世界线赢了，直接返回 1；如果输了，程序会回溯，继续尝试宇宙 2
        if (solve_state(drawn, hA, hP, hE, hR, hGF, hD - 1, energy - 1)) return 1;
    }

    // ================= 平行宇宙 2：打出逃脱计划 =================
    if (hE > 0) {
        int n_drawn = drawn;
        int n_h[6] = {hA, hP, hE - 1, hR, hGF, hD};
        int sz = cur_sz - 1; // 牌打出，容量先-1
        
        if (n_drawn < 21) {
            int c = deck[n_drawn++];
            if (sz < 10) { 
                if (c>=1 && c<=5) n_h[c-1]++; else n_h[5]++;
                sz++;
            }
        }
        if (solve_state(n_drawn, n_h[0], n_h[1], n_h[2], n_h[3], n_h[4], n_h[5], energy)) return 1;
    }

    // ================= 平行宇宙 3：打出早有准备+ =================
    if (hP > 0) {
        int n_drawn = drawn;
        int n_h[6] = {hA, hP - 1, hE, hR, hGF, hD};
        int sz = cur_sz - 1;

        for(int i = 0; i < 2 && n_drawn < 21; i++) {
            int c = deck[n_drawn++];
            if (sz < 10) {
                if (c>=1 && c<=5) n_h[c-1]++; else n_h[5]++;
                sz++;
            }
        }
        // 抽完牌后，进入弃牌阶段的穷举
        if (try_prep_discards(n_drawn, n_h[0], n_h[1], n_h[2], n_h[3], n_h[4], n_h[5], energy)) return 1;
    }

    // ================= 平行宇宙 4：打出杂技+ =================
    if (hA > 0 && energy >= 1) {
        int n_drawn = drawn;
        int n_h[6] = {hA - 1, hP, hE, hR, hGF, hD};
        int sz = cur_sz - 1;

        for(int i = 0; i < 4 && n_drawn < 21; i++) {
            int c = deck[n_drawn++];
            if (sz < 10) {
                if (c>=1 && c<=5) n_h[c-1]++; else n_h[5]++;
                sz++;
            }
        }
        // 抽完牌后，进入弃牌阶段的穷举
        if (try_acro_discards(n_drawn, n_h[0], n_h[1], n_h[2], n_h[3], n_h[4], n_h[5], energy - 1)) return 1;
    }

    // 如果所有合法操作的时间线全部走向失败，则当前牌序真的无药可救
    return 0; 
}

// 早有准备+ 弃牌穷举：尝试弃掉所有可能的 2 张牌组合
int try_prep_discards(int drawn, int hA, int hP, int hE, int hR, int hGF, int hD, int energy) {
    int hand[6] = {hA, hP, hE, hR, hGF, hD};
    int total_cards = hA + hP + hE + hR + hGF + hD;

    if (total_cards == 0) return solve_state(drawn, hA, hP, hE, hR, hGF, hD, energy);
    
    // 极端情况：抽完只剩1张牌，被迫全弃
    if (total_cards == 1) {
        for(int i=0; i<6; i++) {
            if (hand[i] > 0 && i != 4) { // 强行弃华丽收场等于自杀，直接剪枝
                int n_h[6] = {hA, hP, hE, hR, hGF, hD};
                n_h[i]--;
                int reflex_trigger = (i == 3);
                int n_drawn = drawn;
                int sz = total_cards - 1;

                if (reflex_trigger) {
                    for(int k=0; k<3 && n_drawn < 21; k++) {
                        int c = deck[n_drawn++];
                        if (sz < 10) {
                            if (c>=1 && c<=5) n_h[c-1]++; else n_h[5]++;
                            sz++;
                        }
                    }
                }
                if (solve_state(n_drawn, n_h[0], n_h[1], n_h[2], n_h[3], n_h[4], n_h[5], energy)) return 1;
            }
        }
        return 0;
    }

    // 常规情况：双重循环遍历所有 2 张牌的弃牌组合
    for(int i = 0; i < 6; i++) {
        if (hand[i] > 0 && i != 4) {
            hand[i]--;
            for(int j = i; j < 6; j++) { // j 从 i 开始，避免把“弃A弃B”和“弃B弃A”算作两次
                if (hand[j] > 0 && j != 4) {
                    hand[j]--;
                    
                    int reflex_trigger = (i == 3) || (j == 3);
                    int n_drawn = drawn;
                    int n_h[6] = {hand[0], hand[1], hand[2], hand[3], hand[4], hand[5]};
                    int sz = total_cards - 2;

                    if (reflex_trigger) {
                        for(int k=0; k<3 && n_drawn < 21; k++) {
                            int c = deck[n_drawn++];
                            if (sz < 10) {
                                if (c>=1 && c<=5) n_h[c-1]++; else n_h[5]++;
                                sz++;
                            }
                        }
                    }
                    if (solve_state(n_drawn, n_h[0], n_h[1], n_h[2], n_h[3], n_h[4], n_h[5], energy)) return 1;
                    
                    hand[j]++; // 回溯，尝试下一种组合
                }
            }
            hand[i]++; // 回溯
        }
    }
    return 0;
}

// 杂技+ 弃牌穷举：尝试弃掉手里的每一张牌
int try_acro_discards(int drawn, int hA, int hP, int hE, int hR, int hGF, int hD, int energy) {
    int hand[6] = {hA, hP, hE, hR, hGF, hD};
    int total_cards = hA + hP + hE + hR + hGF + hD;

    if (total_cards == 0) return solve_state(drawn, hA, hP, hE, hR, hGF, hD, energy);

    for(int i = 0; i < 6; i++) {
        if (hand[i] > 0 && i != 4) { // 遍历手里所有不是华丽收场的牌
            hand[i]--;
            int reflex_trigger = (i == 3);
            int n_drawn = drawn;
            int n_h[6] = {hand[0], hand[1], hand[2], hand[3], hand[4], hand[5]};
            int sz = total_cards - 1;

            if (reflex_trigger) {
                for(int k=0; k<3 && n_drawn < 21; k++) {
                    int c = deck[n_drawn++];
                    if (sz < 10) {
                        if (c>=1 && c<=5) n_h[c-1]++; else n_h[5]++;
                        sz++;
                    }
                }
            }
            // 顺着这条时间线往下跑
            if (solve_state(n_drawn, n_h[0], n_h[1], n_h[2], n_h[3], n_h[4], n_h[5], energy)) return 1;
            
            hand[i]++; // 回溯
        }
    }
    return 0;
}

int main() {
    int total = 0, success = 0;
    
    // 生成 19,535,040 种宇宙本源排列
    for(int a1=0; a1<21; a1++) {
        for(int a2=a1+1; a2<21; a2++) {
            for(int p=0; p<21; p++) {
                if(p==a1||p==a2) continue;
                for(int e=0; e<21; e++) {
                    if(e==a1||e==a2||e==p) continue;
                    for(int r=0; r<21; r++) {
                        if(r==a1||r==a2||r==p||r==e) continue;
                        for(int gf=0; gf<21; gf++) {
                            if(gf==a1||gf==a2||gf==p||gf==e||gf==r) continue;

                            for(int i=0; i<21; i++) deck[i] = 0;
                            deck[a1] = 1; deck[a2] = 1; deck[p] = 2; 
                            deck[e] = 3; deck[r] = 4; deck[gf] = 5;

                            int init_h[6] = {0};
                            int drawn = 0;
                            for(int i=0; i<7; i++) {
                                int c = deck[drawn++];
                                if (c>=1 && c<=5) init_h[c-1]++; else init_h[5]++;
                            }

                            // 启动上帝视角穷举
                            if (solve_state(drawn, init_h[0], init_h[1], init_h[2], init_h[3], init_h[4], init_h[5], 3)) {
                                success++;
                            }
                            total++;
                        }
                    }
                }
            }
        }
    }

    printf("Denominator (Total states): %d\n", total);
    printf("Numerator (God-mode success): %d\n", success);
    
    // 这个打印出来的概率，就是最纯粹的数学真理
    printf("Absolute Max Win Rate: %.4f%%\n", (double)success / total * 100.0);

    return 0;
}