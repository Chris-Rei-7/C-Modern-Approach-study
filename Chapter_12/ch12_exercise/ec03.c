#include <stdio.h>

#define MAX_LEN 100 // 设定句子最大长度

int main(void) {
    char sentence[MAX_LEN];
    char terminator = '.'; // 用于保存句子结尾的标点符号
    char ch;
    
    // 声明我们在算法中需要的指针
    char *p = sentence; 
    char *q;
    char *word_end;

    printf("Enter a sentence: ");

    // ----------------------------------------------------
    // 第一阶段：用指针 p 顺序录入字符
    // ----------------------------------------------------
    while ((ch = getchar()) != '\n' && p < sentence + MAX_LEN) {
        // 如果遇到终止符，保存它并立刻结束录入循环
        if (ch == '.' || ch == '?' || ch == '!') {
            terminator = ch;
            break; 
        }
        *p++ = ch; // 将字符存入当前位置，然后指针 p 自动向后挪一格
    }

    printf("Reversal of sentence: ");

    // ----------------------------------------------------
    // 第二阶段：反向扫描并打印
    // ----------------------------------------------------
    // 录入结束后，p 停在最后一个有效字符的下一个位置。
    // 所以 p - 1 才是句子里最后一个字母的准确地址。
    word_end = p - 1; 

    // 指针 p 从最后一个字母开始，一路倒退回数组的首地址 (sentence)
    for (p = word_end; p >= sentence; p--) {
        
        // 情况 A：遇到空格，说明找到了一个单词的开头
        if (*p == ' ') {
            // 用另一个指针 q，从空格的后一个字母开始，顺着打印到 word_end
            for (q = p + 1; q <= word_end; q++) {
                putchar(*q);
            }
            putchar(' '); // 单词打印完后，补上一个空格
            
            // 更新 word_end，让它指向下一个待处理单词的尾部（即当前空格的前一格）
            word_end = p - 1; 
        } 
        
        // 情况 B：p 已经退回到了数组的最开头（说明这是句子里的第一个单词）
        else if (p == sentence) {
            // 直接从开头打印到当前的 word_end
            for (q = p; q <= word_end; q++) {
                putchar(*q);
            }
        }
    }

    // ----------------------------------------------------
    // 第三阶段：补上最初保存的标点符号
    // ----------------------------------------------------
    printf("%c\n", terminator);

    return 0;
}