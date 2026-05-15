#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50   /* 最大备忘录条数 */
#define MSG_LEN 60      /* 备忘录消息的最大长度 */

int read_line(char str[], int n);

int main(void)
{
    // 【修改】数组第二维增加了长度，以容纳 "MM/DD HH:MM " 这样更长的时间前缀
    char reminders[MAX_REMIND][MSG_LEN + 15]; 
    char time_str[15], msg_str[MSG_LEN + 1];
    
    // 【新增】增加了 month (月), hours (时), minutes (分) 变量
    int month, day, hours, minutes, i, j, num_remind = 0;

    for (;;) {
        if (num_remind == MAX_REMIND) {
            printf("-- No space left --\n");
            break;
        }

        // 【修改 c & b】提示用户按 月/日 时:分 的格式输入
        printf("Enter month/day, time (HH:MM) and reminder: ");
        
        // 读取 月/日。如果月为 0，则退出程序
        scanf("%d/%d", &month, &day);
        if (month == 0 || day == 0) break;
        
        // 读取 24小时制的时间
        scanf("%d:%d", &hours, &minutes);

        // 【新增 a】错误数据拦截校验
        if (month < 1 || month > 12 || day < 1 || day > 31 ||
            hours < 0 || hours > 23 || minutes < 0 || minutes > 59) {
            
            printf("Error: Invalid date or time. Reminder ignored.\n");
            
            // 【关键清理操作】如果输入错误，缓冲区里还会残留乱七八糟的字符和回车
            // 必须把它们全部吃掉，否则会影响下一次循环的 scanf
            while (getchar() != '\n')
                ; 
            
            continue; // 直接跳过本次循环后面的代码，重新开始下一轮录入
        }

        read_line(msg_str, MSG_LEN);

        // 【修改 b & c】格式化终极对齐术
        // 使用 %02d 强制补零（如 5月变成 05，8点变成 08），这对于 strcmp 的正确排序至关重要！
        sprintf(time_str, "%02d/%02d %02d:%02d ", month, day, hours, minutes);

        // 寻找插入位置（依然依靠 strcmp 的字典序比较）
        for (i = 0; i < num_remind; i++)
            if (strcmp(time_str, reminders[i]) < 0)
                break;

        // 将数据往后移位，腾出空位
        for (j = num_remind; j > i; j--)
            strcpy(reminders[j], reminders[j-1]);

        // 拼接并存入空位
        strcpy(reminders[i], time_str);
        strcat(reminders[i], msg_str);

        num_remind++;
    }

    // 最终输出打印
    printf("\n--- Yearly Reminder List ---\n");
    for (i = 0; i < num_remind; i++)
        printf(" %s\n", reminders[i]);

    return 0;
}

// 辅助函数：读取一行字符串
int read_line(char str[], int n)
{
    int ch, i = 0;
    while ((ch = getchar()) != '\n') {
        if (i < n)
            str[i++] = ch;
    }
    str[i] = '\0';
    return i;
}  