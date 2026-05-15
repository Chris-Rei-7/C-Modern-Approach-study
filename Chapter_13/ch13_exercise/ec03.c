#include <stdio.h>
#include <string.h>

#define MAX_WORDS 50  // 最多接收 50 个单词
#define WORD_LEN 20   // 每个单词最长 20 个字母

int main(void) {
    char words[MAX_WORDS][WORD_LEN + 1]; // 自己打造的 "argv"
    int count = 0;                       // 自己打造的 "argc"

    printf("请输入一串单词 (用空格隔开，按回车结束): ");

    // 只要还没装满，并且成功读到了一个单词
    while (count < MAX_WORDS && scanf("%20s", words[count]) == 1) {
        count++; // 单词数 + 1
        
        // 【核心魔法】紧接着看一眼这个单词后面的字符是什么
        // 如果用户敲了回车，getchar() 就会抓到 '\n'，循环立刻结束！
        if (getchar() == '\n') {
            break; 
        }
    }

    printf("逆序输出: ");
    // 逻辑和之前一模一样，从最后一个单词开始倒着打印
    for (int i = count - 1; i >= 0; i--) {
        printf("%s ", words[i]);
    }
    printf("\n");

    return 0;
}