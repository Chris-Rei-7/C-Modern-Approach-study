#include <stdio.h>

int main(void) {
    char ch;

    printf("Enter phone number: ");

    // 使用 getchar() 逐个读取字符，直到遇到换行符（用户按下回车）
    while ((ch = getchar()) != '\n') {
        
        // 使用 switch 语句进行字母到数字的映射
        switch (ch) {
            // 利用 switch 的“穿透（fall-through）”特性，把同一组字母归拢处理
            case 'A': case 'B': case 'C':
                putchar('2');
                break;
            case 'D': case 'E': case 'F':
                putchar('3');
                break;
            case 'G': case 'H': case 'I':
                putchar('4');
                break;
            case 'J': case 'K': case 'L':
                putchar('5');
                break;
            case 'M': case 'N': case 'O':
                putchar('6');
                break;
            case 'P': case 'Q': case 'R': case 'S':
                putchar('7');
                break;
            case 'T': case 'U': case 'V':
                putchar('8');
                break;
            case 'W': case 'X': case 'Y': case 'Z':
                putchar('9');
                break;
            // 如果不是上面这些大写字母（比如本身就是数字、或者是连字符 '-'）
            // 就直接原样输出
            default:
                putchar(ch);
                break;
        }
    }
    
    // 整个号码打印完后，补上一个换行符，让终端输出更美观
    putchar('\n');

    return 0;
}