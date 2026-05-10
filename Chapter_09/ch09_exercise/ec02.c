#include <stdio.h>
int year (int x, int y){
    int z;
    z=x%y;
    if(z!=0)
    year(y,z);
    if(z==0)
    return y;
}
int main(void) {
    int x,y;
    scanf("%d %d", &x, &y);
    printf("%d",year (x,y));
    return 0;
}