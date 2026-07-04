#include <stdio.h>
int main()
{
    int n = 5;
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n - 1; j++)
            printf(" ");
        for(char ch = 'A'; ch <= 'A' + i; ch++)
            printf("%c", ch);
        for(char ch = 'A' + i - 1; ch >= 'A'; ch--)
            printf("%c", ch);
        printf("\n");
    }
    for(int i = n - 2; i >= 0; i--)
    {
        for(int j = n - 1; j > i; j--)
            printf(" ");
        for(char ch = 'A'; ch <= 'A' + i; ch++)
            printf("%c", ch);
        for(char ch = 'A' + i - 1; ch >= 'A'; ch--)
            printf("%c", ch);
        printf("\n");
    }
    return 0;
}
