#include <stdio.h>
int main()
{
    int units;
    float bill;
    printf("Enter electricity units: ");
    scanf("%d", &units);
    if(units <= 100)
        bill = units * 1.5;
    else if(units <= 300)
        bill = 150 + (units - 100) * 2.5;
    else
        bill = 650 + (units - 300) * 4.0;
    printf("Total Bill = %.2f", bill);
    return 0;
}
