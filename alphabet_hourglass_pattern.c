#include <stdio.h>
int main()
{
    int n = 5;
    for(int i = n; i >= 1; i--)
    {
        for(int j = 0; j < n - i; j++)
            printf(" ");
        for(char ch = 'A'; ch < 'A' + i; ch++)
            printf("%c", ch);
        printf("\n");
    }
    for(int i = 2; i <= n; i++)
    {
        for(int j = 0; j < n - i; j++)
            printf(" ");
        for(char ch = 'A'; ch < 'A' + i; ch++)
            printf("%c", ch);
        printf("\n");
    }
    return 0;
}
