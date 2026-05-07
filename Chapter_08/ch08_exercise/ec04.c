#include <stdio.h>

int main(void) {
    char ch;
    
    // 建立一个长度为 26 的“查找表” (Lookup Table)
    // 对应关系: A B C (2) | D E F (3) | G H I (4) | ... | W X Y Z (9)
    int phone_map[26] = {
        2, 2, 2,       // A, B, C
        3, 3, 3,       // D, E, F
        4, 4, 4,       // G, H, I
        5, 5, 5,       // J, K, L
        6, 6, 6,       // M, N, O
        7, 7, 7, 7,    // P, Q, R, S
        8, 8, 8,       // T, U, V
        9, 9, 9, 9     // W, X, Y, Z
    };

    printf("Enter phone number: ");

    while ((ch = getchar()) != '\n') {
        // 判断如果当前字符是大写字母 A 到 Z
        if (ch >= 'A' && ch <= 'Z') {
            // 核心魔法：使用字符的 ASCII 码偏移量作为数组下标
            printf("%d", phone_map[ch - 'A']);
        } else {
            // 如果是数字或连字符等其他字符，原样输出
            putchar(ch);
        }
    }
    
    printf("\n");

    return 0;
}