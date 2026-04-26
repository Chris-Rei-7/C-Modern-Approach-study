#include <stdio.h>

int main(void) {
    int num;
    int d1, d2, d3, d4, d5;

    printf("Enter a number between 0 and 32767: ");
    scanf("%d", &num);

    // 从右到左（从低位到高位）依次提取八进制位
    d5 = num % 8;  // 提取最后一位
    num = num / 8; // 砍掉最后一位

    d4 = num % 8;  // 提取倒数第二位
    num = num / 8;

    d3 = num % 8;  // 提取倒数第三位
    num = num / 8;

    d2 = num % 8;  // 提取倒数第四位
    num = num / 8;

    d1 = num % 8;  // 提取最高位（第一位）

    // 按照从高位到低位的顺序（d1 到 d5）拼接打印
    printf("In octal, your number is: %d%d%d%d%d\n", d1, d2, d3, d4, d5);

    return 0;
}
