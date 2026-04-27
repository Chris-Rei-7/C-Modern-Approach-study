#include <stdio.h>

int main(void) {
    int num, tens, ones;

    printf("Enter a two-digit number: ");
    scanf("%d", &num);

    // 把两位数拆分为十位数和个位数
    tens = num / 10;
    ones = num % 10;

    printf("You entered the number ");

    // 特殊情况：处理 10 ~ 19
    if (tens == 1) {
        switch (ones) {
            case 0: printf("ten.\n"); break;
            case 1: printf("eleven.\n"); break;
            case 2: printf("twelve.\n"); break;
            case 3: printf("thirteen.\n"); break;
            case 4: printf("fourteen.\n"); break;
            case 5: printf("fifteen.\n"); break;
            case 6: printf("sixteen.\n"); break;
            case 7: printf("seventeen.\n"); break;
            case 8: printf("eighteen.\n"); break;
            case 9: printf("nineteen.\n"); break;
        }
    } 
    // 常规情况：处理 20 ~ 99
    else {
        // 第一个 switch 语句：输出十位对应的单词
        switch (tens) {
            case 2: printf("twenty"); break;
            case 3: printf("thirty"); break;
            case 4: printf("forty"); break;  // ⚠️ 易错提醒：40 拼写是 forty，不是 fourty
            case 5: printf("fifty"); break;
            case 6: printf("sixty"); break;
            case 7: printf("seventy"); break;
            case 8: printf("eighty"); break;
            case 9: printf("ninety"); break;
        }

        // 第二个 switch 语句：输出个位对应的单词（如果有的话）
        if (ones != 0) {
            switch (ones) {
                case 1: printf("-one.\n"); break;
                case 2: printf("-two.\n"); break;
                case 3: printf("-three.\n"); break;
                case 4: printf("-four.\n"); break;
                case 5: printf("-five.\n"); break;
                case 6: printf("-six.\n"); break;
                case 7: printf("-seven.\n"); break;
                case 8: printf("-eight.\n"); break;
                case 9: printf("-nine.\n"); break;
            }
        } else {
            // 如果个位是 0（如 20, 30），直接打个句号并换行
            printf(".\n");
        }
    }

    return 0;
}