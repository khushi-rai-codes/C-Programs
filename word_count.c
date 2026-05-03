#include<stdio.h>
#include<string.h>
int main()
{
    char str[200];
    int count = 0;
    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);
    for(int i = 0; str[i] != '\0'; i++)
    {
        if((i == 0 && str[i] != ' ' && str[i] != '\n') ||
           (str[i] == ' ' && str[i + 1] != ' ' && str[i + 1] != '\0' && str[i + 1] != '\n'))
        {
            count++;
        }
    }
    printf("Number of words = %d", count);
    return 0;
}
