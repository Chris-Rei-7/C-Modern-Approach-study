#include <stdio.h>
int main(void)
{
    int a,b,c,d,e;
    printf("Enter IBSM:");
    scanf("%d-%d-%d-%d-%d", &a, &b, &c, &d, &e);
    printf("GS1 prefix:%d\nGroup identifier:%d\nPublisher code:%d\nItem number:%d\nCheck digit:%d\n", a, b, c, d, e);
    return 0;
}