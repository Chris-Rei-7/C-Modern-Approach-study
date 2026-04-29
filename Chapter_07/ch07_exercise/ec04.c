#include <stdio.h>
#include <math.h>
int main(void){
double x,y,z,a,b;
printf("Enter a positive number:");
scanf("%lf",&x);
for(y=1;;){
    z=x/y;
    a=(z+y)/2;
    if(fabs(y-a)<0.00001*y)
        break;
    y=a;

}
printf("Square root:%lf",a);
return 0;
}