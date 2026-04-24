#include <stdio.h>
int main(void)
{
    int day, month, year;
    scanf("%d/%d/%d", &day, &month, &year);
    printf("You entered the date %d/%d/%d\n", day, month, year);
    return 0;
}