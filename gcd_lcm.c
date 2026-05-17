#include<stdio.h>
int main()
{
    int a, b, gcd, lcm;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    int x = a, y = b;
    while(y != 0)
    {
        int temp = y;
        y = x % y;
        x = temp;
    }
    gcd = x;
    lcm = (a * b) / gcd;
    printf("GCD = %d\n", gcd);
    printf("LCM = %d", lcm);
    return 0;
}
