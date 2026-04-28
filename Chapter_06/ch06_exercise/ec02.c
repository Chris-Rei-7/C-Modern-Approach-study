#include <stdio.h>
int main(void)
{
    printf("Please enter two numbers");
    int a,b,c;
    scanf("%d %d",&a,&b);
    while (b>0)
    {
        c=a;
        a=b;
        b=c%b;  
    }
    printf("%d",a);
    return 0;
}
