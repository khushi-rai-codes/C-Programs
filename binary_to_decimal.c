#include<stdio.h>
#include<math.h>
int main()
{
    int binary, decimal = 0, base = 0, remainder;
    printf("Enter a binary number: ");
    scanf("%d", &binary);
    while(binary > 0)
    {
        remainder = binary % 10;
        decimal += remainder * pow(2, base);
        binary = binary / 10;
        base++;
    }
    printf("Decimal = %d", decimal);
    return 0;
}
