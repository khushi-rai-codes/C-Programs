#include<stdio.h>
int main()
{
    int num, octal[32], i = 0;
    printf("Enter a decimal number: ");
    scanf("%d", &num);
    if(num == 0)
    {
        printf("Octal = 0");
        return 0;
    }
    while(num > 0)
    {
        octal[i] = num % 8;
        num = num / 8;
        i++;
    }
    printf("Octal = ");
    for(int j = i - 1; j >= 0; j--)
    {
        printf("%d", octal[j]);
    }
    return 0;
}
