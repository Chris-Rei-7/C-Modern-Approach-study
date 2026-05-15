#include <stdio.h>
#include <stdlib.h> // 必须包含！atoi 函数的家

int main(void) {
    char word[20];  // 准备一个临时的小盒子，用来装单个被切下来的字符串
    int total = 0;  // 计分板

    printf("请输入一串整数进行求和 (用空格隔开，按回车结束): ");

    // %19s 表示最多读 19 个字符当成字符串（留 1 个位置给 '\0'）
    // scanf 会自动以空格为界限，一次切下一个“词”放进 word 里
    while (scanf("%19s", word) == 1) {
        
        // 核心步骤：此时 word 里面装的是字符串（比如 "24"）
        // 我们用 atoi 把它翻译成真正的整数 24，并加到 total 里
        total += atoi(word);
        
        // 探测魔法：看看切完这个词之后，后面跟着的是不是回车符
        if (getchar() == '\n') {
            break; // 如果是回车，说明输入结束，打断循环
        }
    }

    printf("Total: %d\n", total);

    return 0;
}