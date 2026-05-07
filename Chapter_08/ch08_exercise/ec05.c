#include <stdio.h>
#define MAX_LEN 200 // 定义句子的最大长度

int main(void)
 {
    char sentence[MAX_LEN];
    char ch, terminator = '.'; // 默认终止符，防止用户没输入标点
    int length = 0;
    printf("Enter a sentence: ");
    while ((ch = getchar()) != '\n' && length < MAX_LEN) {
        if (ch == '.' || ch == '?' || ch == '!') {
            terminator = ch; // 保存这个“终止字符”
            break;           // 抛弃标点，停止录入数组
        }
        sentence[length] = ch;
        length++;
    }
    //  阶段 2：反向扫描，切分并打印单词
    int word_end = length; // 记录当前正在处理的单词的“右边界”

    // 游标 i 从数组的最末尾开始，一步步往回退
    for (int i = length - 1; i >= 0; i--) {
        
        // 如果游标 i 踩到了空格，说明找到了一个单词的“左边界”
        if (sentence[i] == ' ') {
            
            // 从空格的下一个字符 (i+1) 开始，正向打印到这个单词的右边界 (word_end)
            for (int j = i + 1; j < word_end; j++) {
                putchar(sentence[j]);
            }
            putchar(' ');  // 单词打完了，补上一个空格

            word_end = i;  // 【核心机制】：把当前的空格位置，变成下一个单词的“右边界”
        }
    }

    //  阶段 3：打印第一个单词（跳出循环后的收尾工作）
    // 因为句子的第一个单词前面是没有空格的，所以上面的 for 循环抓不到它
    for (int j = 0; j < word_end; j++) {
        putchar(sentence[j]);
    }

    //  阶段 4：最后补上刚刚保存的标点符号
    printf("%c\n", terminator);

    return 0;
}