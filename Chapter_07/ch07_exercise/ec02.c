#include <stdio.h>

int main(void) {
    // 使用 %zu 格式说明符来打印 sizeof 返回的 size_t 类型值
    printf("Size of int:         %zu bytes\n", sizeof(int));
    printf("Size of short:       %zu bytes\n", sizeof(short));
    printf("Size of long:        %zu bytes\n", sizeof(long));
    printf("Size of float:       %zu bytes\n", sizeof(float));
    printf("Size of double:      %zu bytes\n", sizeof(double));
    printf("Size of long double: %zu bytes\n", sizeof(long double));

    return 0;
}