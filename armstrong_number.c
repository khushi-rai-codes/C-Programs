#include<stdio.h>
#include<math.h>
int main()
{
    int num, original, remainder;
    int result = 0;
    printf("Enter a number: ");
    scanf("%d", &num);
    original = num;
    while(num != 0)
    {
        remainder = num % 10;
        result = result + pow(remainder, 3);
        num = num / 10;
    }
    if(original == result)
        printf("Armstrong number");
    else
        printf("Not an Armstrong number");
    return 0;
}
