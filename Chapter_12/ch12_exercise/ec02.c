#include <stdio.h>
#include <ctype.h> // 需要用到 isalpha 和 tolower

#define MAX_LEN 100

int main(void) {
    char msg[MAX_LEN];
    char *p = msg;
    char ch;

    printf("Enter a message: ");

    // 1. 数据清洗与录入
    while ((ch = getchar()) != '\n' && p < msg + MAX_LEN) {
        if (isalpha(ch)) {       // 如果是英文字母
            *p = tolower(ch);    // 强制转为小写后存入
            p++;
        }
    }

    // 2. 准备双指针进行回文检测
    char *left = msg;      // left 指向开头
    char *right = p - 1;   // right 指向最后一个有效字母
    int is_palindrome = 1; // 标志位：先假设它是回文 (1为真)

    // 只要 left 还在 right 的左边，就继续检查
    while (left < right) {
        if (*left != *right) {
            is_palindrome = 0; // 发现不匹配，推翻假设
            break;             // 没必要继续查了，直接跳出循环
        }
        left++;  // 左指针向右走
        right--; // 右指针向左走
    }

    // 3. 输出结果
    if (is_palindrome) {
        printf("Palindrome\n");
    } else {
        printf("Not a palindrome\n");
    }

    return 0;
}