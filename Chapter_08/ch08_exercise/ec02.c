#include <stdio.h>
#include <ctype.h>  // 为了使用 toupper() 函数

#define MAX_MSG_LEN 100 // 定义消息的最大长度

int main(void) {
    char message[MAX_MSG_LEN];
    char ch;
    int i = 0;
    int length;

    // 1. 读取用户输入并存入数组
    printf("Enter message: ");
    // 使用 getchar 逐个读取，直到遇到回车换行，或者达到数组上限
    while ((ch = getchar()) != '\n' && i < MAX_MSG_LEN) {
        message[i] = ch;
        i++;
    }
    length = i; // 记录下实际输入的字符个数

    // 2. 翻译并输出 B1FF 风格的消息
    printf("In B1FF-speak: ");
    for (i = 0; i < length; i++) {
        // 先将字符统一转换为大写
        ch = toupper(message[i]);

        // 使用 switch 语句进行特定的“黑客语”替换
        switch (ch) {
            case 'A': putchar('4'); break;
            case 'B': putchar('8'); break;
            case 'E': putchar('3'); break;
            case 'I': putchar('1'); break;
            case 'O': putchar('0'); break;
            case 'S': putchar('5'); break;
            default:  putchar(ch);  break; // 其他字符原样输出
        }
    }

    // 3. 在末尾追加约 10 个感叹号
    printf("!!!!!!!!!!\n");

    return 0;
}