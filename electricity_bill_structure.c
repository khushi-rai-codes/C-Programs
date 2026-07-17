#include <stdio.h>
struct Consumer
{
    int id;
    char name[50];
    int units;
    float bill;
};
int main()
{
    struct Consumer c;
    printf("Enter Consumer ID: ");
    scanf("%d", &c.id);
    printf("Enter Consumer Name: ");
    scanf("%s", c.name);
    printf("Enter Units Consumed: ");
    scanf("%d", &c.units);
    if(c.units <= 100)
        c.bill = c.units * 1.5;
    else if(c.units <= 300)
        c.bill = 150 + (c.units - 100) * 2.5;
    else
        c.bill = 650 + (c.units - 300) * 4;
    printf("\n----- Bill Details -----\n");
    printf("ID : %d\n", c.id);
    printf("Name : %s\n", c.name);
    printf("Bill : %.2f\n", c.bill);
    return 0;
}
