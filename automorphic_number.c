#include<stdio.h>
int main()
{
    int num, square, temp, digits = 0;
    printf("Enter a number: ");
    scanf("%d", &num);
    square = num * num;
    temp = num;
    while(temp > 0)
    {
        digits++;
        temp = temp / 10;
    }
    int divisor = 1;
    for(int i = 0; i < digits; i++)
    {
        divisor *= 10;
    }
    if(square % divisor == num)
        printf("%d is an Automorphic Number", num);
    else
        printf("%d is not an Automorphic Number", num);
    return 0;
}
