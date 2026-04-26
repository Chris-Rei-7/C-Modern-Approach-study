#include <stdio.h>

int main(void) {
    int num;

    printf("Enter a number between 0 and 32767: ");
    scanf("%d", &num);

    // %05o 一步到位实现转换和补零格式化
    printf("In octal, your number is: %05o\n", num);

    return 0;
}