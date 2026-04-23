#include <stdio.h>
int main(void)
{
    float all,ra,pa,a1,a2,a3;
    printf("Enter amount of loan:");
    scanf("%f",&all);
    printf("Enter interest rate:");
    scanf("%f",&ra);
    printf("Enter monthly payment:");
    scanf("%f",&pa);
    a1=all*(1+ra/1200)-pa;
    a2=a1*(1+ra/1200)-pa;
    a3=a2*(1+ra/1200)-pa;
    printf("Balance after first payment: %.2f\n", a1);
    printf("Balance after second payment: %.2f\n", a2);
    printf("Balance after third payment: %.2f\n", a3);
    return 0;
}

