#include <stdio.h>
int power(int x, int n)
{
 if (n == 0)
 return 1;
 if(n%2!=0)
 return x * power(x, n - 1);
 else
 return power(x*x, n/2);
} 
int main(void) {
    int x,y;
    scanf("%d %d", &x, &y);
    printf("%d",power(x,y));
    return 0;
}