#include <stdio.h>
#include <ctype.h>

#define MAX_DIGITS 10

// -----------------------------------------
// 1. 全局数据结构定义
// -----------------------------------------
// 声明 3 行、MAX_DIGITS * 4 列的二维字符数组（每个数字占3列 + 1列空格）
char digits[3][MAX_DIGITS * 4];

// 核心密码本：七段数码管映射表 (查表法)
// 每一行代表一个数字(0-9)，7列分别代表段 A, B, C, D, E, F, G 的亮暗 (1为亮，0为暗)
const int segments[10][7] = {
    {1, 1, 1, 1, 1, 1, 0}, // 0
    {0, 1, 1, 0, 0, 0, 0}, // 1
    {1, 1, 0, 1, 1, 0, 1}, // 2
    {1, 1, 1, 1, 0, 0, 1}, // 3
    {0, 1, 1, 0, 0, 1, 1}, // 4
    {1, 0, 1, 1, 0, 1, 1}, // 5
    {1, 0, 1, 1, 1, 1, 1}, // 6
    {1, 1, 1, 0, 0, 0, 0}, // 7
    {1, 1, 1, 1, 1, 1, 1}, // 8
    {1, 1, 1, 1, 0, 1, 1}  // 9
};

// 函数声明
void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);

// -----------------------------------------
// 2. 主逻辑
// -----------------------------------------
int main(void) {
    char ch;
    int position = 0;

    // 第一步：清空画布
    clear_digits_array();

    printf("Enter a number: ");
    
    // 第二步：逐个读取字符，录入画布
    while ((ch = getchar()) != '\n' && position < MAX_DIGITS) {
        if (isdigit(ch)) {
            // 将字符转换为真正的数字整数，并处理它
            process_digit(ch - '0', position);
            position++; // 只有遇到有效的数字，位置才向后挪一个
        }
    }

    // 第三步：一次性将画布打印出来
    print_digits_array();

    return 0;
}

// -----------------------------------------
// 3. 子函数实现
// -----------------------------------------

// 功能：用空格填满整个 digits 二维数组（清空画布）
void clear_digits_array(void) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < MAX_DIGITS * 4; j++) {
            digits[i][j] = ' ';
        }
    }
}

// 功能：将一个数字的七段显示写入到 digits 数组的指定位置
// 功能：将一个数字的七段显示写入到 digits 数组的指定位置
void process_digit(int digit, int position) {
    int offset = position * 4;

    // 顶层 (Row 0)
    if (segments[digit][0]) digits[0][offset + 1] = '_'; // 段 0 (A)
    
    // 中层 (Row 1)
    if (segments[digit][5]) digits[1][offset + 0] = '|'; // 段 5 (F)
    if (segments[digit][6]) digits[1][offset + 1] = '_'; // 段 6 (G)
    // ✅ 修复：正确映射右上角
    if (segments[digit][1]) digits[1][offset + 2] = '|'; // 段 1 (B) 
    
    // 底层 (Row 2)
    if (segments[digit][4]) digits[2][offset + 0] = '|'; // 段 4 (E)
    if (segments[digit][3]) digits[2][offset + 1] = '_'; // 段 3 (D)
    // ✅ 修复：正确映射右下角
    if (segments[digit][2]) digits[2][offset + 2] = '|'; // 段 2 (C) 
}
// 功能：逐行打印出 digits 数组的内容
void print_digits_array(void) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < MAX_DIGITS * 4; j++) {
            putchar(digits[i][j]);
        }
        putchar('\n'); // 一行打完后换行
    }
}