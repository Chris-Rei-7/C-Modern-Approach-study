#include <stdio.h>
int main(void)
{  
 float a,b,max;
 scanf("%f",&a);
 max=a;
 if(a>0)
 while(1)
 {
 scanf("%f",&b);
 if (b>a)
 max=b;
 else if(b<=0) break;
 a=b;
 }
 printf("max=%.2f",max);
 return 0;
}