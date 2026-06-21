#include <stdio.h>
int main()
{
    int n = 5;
    for(int i = 1; i <= n; i++)
    {
        for(int j = i; j < n; j++)
            printf(" ");
        for(int j = i; j >= 1; j--)
            printf("%d", j);
        for(int j = 2; j <= i; j++)
            printf("%d", j);
        printf("\n");
    }
    return 0;
}
