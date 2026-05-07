#include <stdio.h>

int main(void) {
    int n;

    // 1. 打印提示语并获取用户输入
    printf("This program creates a magic square of a specified size.\n");
    printf("The size must be an odd number between 1 and 99.\n");
    printf("Enter size of magic square: ");
    scanf("%d", &n);

    // 简单校验一下用户的输入是否合法（必须是奇数）
    if (n % 2 == 0) {
        printf("Error: Size must be an odd number.\n");
        return 1;
    }

    // 2. 声明变长数组 (VLA)，并把所有元素初始化为 0
    // 初始化为 0 非常关键，这样我们就能用 0 来判断某个格子是否“被占用”
    int magic[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            magic[i][j] = 0;
        }
    }
    int t=1,j=n/2,i=0;
    while (t<=n*n)
    {   
        if(i<0&&j<=n-1)
        i=n-1;
        if(j>n-1&&i>=0)        
        j=0;
        if(i<0&&j>n-1)
        {
            i+=2;
            j--;
        }
        if(i>=0&&j<=n-1)
        if(magic[i][j]!=0)
        {
            i+=2;
            j--;
        }
        magic[i][j] = t;
        t++;
        i--;
        j++;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%5d", magic[i][j]);
        }
        printf("\n");
    }

    return 0;
}
 
