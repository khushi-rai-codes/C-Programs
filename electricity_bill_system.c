#include<stdio.h>
int main()
{
    int units;
    float bill;
    printf("Enter electricity units consumed: ");
    scanf("%d", &units);
    if(units <= 100)
    {
        bill = units * 1.5;
    }
    else if(units <= 300)
    {
        bill = (100 * 1.5) + ((units - 100) * 2.5);
    }
    else
    {
        bill = (100 * 1.5) + (200 * 2.5) + ((units - 300) * 4);
    }
    printf("Total Electricity Bill = %.2f", bill);
    return 0;
}
