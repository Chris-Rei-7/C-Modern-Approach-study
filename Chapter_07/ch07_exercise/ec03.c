#include <stdio.h>

int main(void) {
    char ch, initial;

    printf("Enter a first and last name: ");

    // 第一阶段：跳过输入最前面的所有空格（如果有的话）
    while ((ch = getchar()) == ' ')
        ;
    
    // 此时 ch 里装的必定是名字的第一个字母，把它存下来！
    initial = ch;

    // 第二阶段：跳过名字的剩余部分，直到遇到第一个空格
    while ((ch = getchar()) != ' ')
        ;

    // 第三阶段：跳过名字和姓氏中间可能存在的多个空格
    while ((ch = getchar()) == ' ')
        ;

    // 第四阶段：开始打印姓氏。
    // 此时 ch 里已经装了姓氏的第一个字母了，所以用 do-while 循环先打印，再继续读
    do {
        putchar(ch);
    } while ((ch = getchar()) != ' ' && ch != '\n'); // 遇到换行或姓氏后面的空格就停下

    // 第五阶段：按照题目格式要求，补齐逗号、首字母和句号
    printf(", %c.\n", initial);

    return 0;
}