#include <stdio.h>

#define MAX_LEN 100

int main(void) {
    char msg[MAX_LEN];
    char *p = msg; // p 初始指向数组的首地址 (等同于 &msg[0])
    char ch;

    printf("Enter a message: ");

    // 录入阶段：用 p 滑行录入
    while ((ch = getchar()) != '\n' && p < msg + MAX_LEN) {
        *p = ch;   // 将字符存入当前 p 指向的格子
        p++;       // p 往后移动一格
        // 上面两行可以被老手缩写为极其经典的： *p++ = ch;
    }

    printf("Reversal is: ");
    
    // 逆序打印阶段：此时 p 停在最后一个字符的"下一个"空白位置
    // 所以必须先 p-- 退一格，然后一路往回走，直到退回首地址 msg
    for (p--; p >= msg; p--) {
        putchar(*p);
    }
    printf("\n");

    return 0;
}