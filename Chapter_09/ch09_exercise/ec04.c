#include <stdio.h>   // 必须保留：用于 printf 和 scanf
#include <stdlib.h>  // 必须保留：用于 rand() 和 srand()
#include <time.h>    // 必须保留：用于 time() 生成真随机种子

// 函数声明：把返回值从 bool 改回普通的 int
int roll_dice(void);
int play_game(void);

int main(void) {
    int wins = 0;
    int losses = 0;
    char play_again;

    srand((unsigned) time(NULL));

    do {
        // play_game 返回 1 代表赢，返回 0 代表输
        if (play_game() == 1) {
            wins++;
        } else {
            losses++;
        }

        printf("\nPlay again? ");
        scanf(" %c", &play_again);
        printf("\n");

    // 直接判断字符是否等于大写 Y 或小写 y，省去了字符处理库
    } while (play_again == 'Y' || play_again == 'y'); 

    printf("Wins: %d  Losses: %d\n", wins, losses);

    return 0;
}

int roll_dice(void) {
    int dice1 = rand() % 6 + 1;
    int dice2 = rand() % 6 + 1;
    return dice1 + dice2;
}

int play_game(void) {
    int roll = roll_dice();
    printf("You rolled: %d\n", roll);

    if (roll == 7 || roll == 11) {
        printf("You win!\n");
        return 1; // 返回 1 替代 true
    } else if (roll == 2 || roll == 3 || roll == 12) {
        printf("You lose!\n");
        return 0; // 返回 0 替代 false
    }

    int point = roll;
    printf("Your point is %d\n", point);

    while (1) {
        roll = roll_dice();
        printf("You rolled: %d\n", roll);
        
        if (roll == point) {
            printf("You win!\n");
            return 1;
        } else if (roll == 7) {
            printf("You lose!\n");
            return 0;
        }
    }
}