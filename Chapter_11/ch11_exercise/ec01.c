#include <stdio.h>

#define N 10 // 定义数组的长度

// 1. 提前声明函数原型 (让 main 函数认识它)
void find_two_largest(int a[], int n, int *largest, int *second_largest);

int main(void) {
    int my_array[N];
    int max;         // 准备用来接“最大值”的变量
    int second_max;  // 准备用来接“第二大值”的变量

    // 提示用户输入数组元素
    printf("Enter %d numbers: ", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &my_array[i]);
    }

    // 2. 核心调用：注意这里必须加上 '&' 取地址符！
    // 我们把 max 和 second_max 的内存地址交给了函数，
    // 这样函数内部就能顺着地址直接把结果写进这两个变量里。
    find_two_largest(my_array, N, &max, &second_max);

    // 3. 打印结果，此时 max 和 second_max 已经被子函数修改过了
    printf("\nLargest: %d\n", max);
    printf("Second largest: %d\n", second_max);

    return 0;
}

// ---------------------------------------------------------
// 之前写好的核心处理函数
// ---------------------------------------------------------
void find_two_largest(int a[], int n, int *largest, int *second_largest) {
    // 安全防护：如果数组连2个元素都没有，就没必要找了
    if (n < 2) return; 

    // 初始基准：先拿数组的前两个元素来初始化老大和老二
    if (a[0] > a[1]) {
        *largest = a[0];
        *second_largest = a[1];
    } else {
        *largest = a[1];
        *second_largest = a[0];
    }

    // 打擂台：从第三个元素（下标2）开始遍历，不断挑战
    for (int i = 2; i < n; i++) {
        if (a[i] > *largest) {
            *second_largest = *largest; // 旧老大变老二
            *largest = a[i];            // 新皇登基
        } else if (a[i] > *second_largest) {
            *second_largest = a[i];     // 干掉老二，自己上位
        }
    }
}