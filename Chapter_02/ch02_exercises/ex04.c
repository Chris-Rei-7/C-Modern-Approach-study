#include <stdio.h>
int main(void)
{
    int all;
    int num1=20,num2=10,num3=5,num4=1;
    printf("Enter a dollar amount: ");
    scanf ("%d", &all);
    printf("$20 bills: %d\n", all/num1);
    printf("$10 bills: %d\n", (all % num1) / num2);
    printf(" $5 bills: %d\n", ((all % num1) % num2) / num3);
    printf(" $1 bills: %d\n", (((all % num1) % num2) % num3) / num4);
    return 0;
}
