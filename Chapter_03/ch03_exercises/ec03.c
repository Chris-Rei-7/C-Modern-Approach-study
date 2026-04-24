#include <stdio.h>
int main(void)
{
    int n,a,b,c;
    float p;
    printf("Enter item number: ");
    scanf("%d", &n);
    printf("Enter unit price: ");
    scanf("%f", &p);
    printf("Enter purchase date (mm/dd/yyyy):");
    scanf("%d/%d/%d", &a, &b, &c);
    printf("Item\tUnit\tPurchase\n");
    printf("\tPrice\tDate\n");
    printf("%d\t$%7.2f\t%d/%d/%d\n", n, p, a, b, c);
    return 0;
}