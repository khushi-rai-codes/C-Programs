#include<stdio.h>
int main()
{
    int num, temp, isDuck = 0;
    printf("Enter a number: ");
    scanf("%d", &num);
    temp = num;
    while(temp > 0)
    {
        if(temp % 10 == 0)
        {
            isDuck = 1;
            break;
        }
        temp = temp / 10;
    }
    if(isDuck)
        printf("%d is a Duck Number", num);
    else
        printf("%d is not a Duck Number", num);
    return 0;
}
