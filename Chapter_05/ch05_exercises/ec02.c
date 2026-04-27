#include <stdio.h>

int main(void) {
    int hours, minutes, total_mins;

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hours, &minutes); 

    total_mins = hours * 60 + minutes;

    // 完美补丁：处理午夜跨天情况。凌晨 2:52 之前，离昨晚最后一班更近
    if (total_mins <= 172) {
        printf("Closest departure time is 9:45 p.m., arriving at 11:58 p.m.\n");
    } 
    // 后面的逻辑保持不变
    else if (total_mins < 531) {
        printf("Closest departure time is 8:00 a.m., arriving at 10:16 a.m.\n");
    } else if (total_mins < 631) {
        printf("Closest departure time is 9:43 a.m., arriving at 11:52 a.m.\n");
    } else if (total_mins < 723) {
        printf("Closest departure time is 11:19 a.m., arriving at 1:31 p.m.\n");
    } else if (total_mins < 803) {
        printf("Closest departure time is 12:47 p.m., arriving at 3:00 p.m.\n");
    } else if (total_mins < 892) {
        printf("Closest departure time is 2:00 p.m., arriving at 4:08 p.m.\n");
    } else if (total_mins < 1042) {
        printf("Closest departure time is 3:45 p.m., arriving at 5:55 p.m.\n");
    } else if (total_mins < 1222) {
        printf("Closest departure time is 7:00 p.m., arriving at 9:20 p.m.\n");
    } else {
        printf("Closest departure time is 9:45 p.m., arriving at 11:58 p.m.\n");
    }

    return 0;
}