#include <stdio.h>

int main(void) {
    int n1, n2, n3, n4;
    int max1, min1, max2, min2;
    int max_final, min_final;

    printf("Enter four integers: ");
    scanf("%d %d %d %d", &n1, &n2, &n3, &n4);

    // 第 1 条 if：第一组内部比较
    if (n1 > n2) {
        max1 = n1;
        min1 = n2;
    } else {
        max1 = n2;
        min1 = n1;
    }

    // 第 2 条 if：第二组内部比较
    if (n3 > n4) {
        max2 = n3;
        min2 = n4;
    } else {
        max2 = n4;
        min2 = n3;
    }

    // 第 3 条 if：决出最终的最大值
    if (max1 > max2) {
        max_final = max1;
    } else {
        max_final = max2;
    }

    // 第 4 条 if：决出最终的最小值
    if (min1 < min2) {
        min_final = min1;
    } else {
        min_final = min2;
    }

    printf("Largest: %d\n", max_final);
    printf("Smallest: %d\n", min_final);

    return 0;
}