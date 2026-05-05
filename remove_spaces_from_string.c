#include<stdio.h>
#include<string.h>
int main()
{
    char str[200], result[200];
    int j = 0;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] != ' ' && str[i] != '\n')
        {
            result[j++] = str[i];
        }
    }
    result[j] = '\0';
    printf("String without spaces: %s", result);
    return 0;
}
