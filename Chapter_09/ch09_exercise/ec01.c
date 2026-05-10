#include <stdio.h>
int main(void) {
    int n,m=1;
    scanf("%d", &n);
    for(;n>=1;n--)
    {m*=n;
    }
    printf("%d", m);
    return 0;
}