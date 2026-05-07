#include <stdio.h>

int main(void)
{
    // 1. 将布尔数组改为整型数组，并全部初始化为 0
    int digit_counts[10] = {0}; 
    int digit;
    long n;

    printf("Enter a number: ");
    scanf("%ld", &n);

    // 2. 剥离并统计每一个数字
    while (n > 0) {
        digit = n % 10;           // 获取最后一位数字
        digit_counts[digit]++;    // 将对应数字下标的计数器加 1
        n /= 10;                  // 砍掉最后一位
    }

    // 3. 打印表头 (0 到 9 的数字)
    printf("Digit:        ");
    for (int i = 0; i < 10; i++) {
        printf("%3d", i);         // %3d 保证每个数字占 3 个字符宽度，使其对齐
    }
    printf("\n");

    // 4. 打印统计结果 (每个数字出现的次数)
    printf("Occurrences:  ");
    for (int i = 0; i < 10; i++) {
        printf("%3d", digit_counts[i]); 
    }
    printf("\n");

    return 0;
}