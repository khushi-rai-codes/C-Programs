#include<stdio.h>
#include<string.h>
int main()
{
    char str[200];
    char temp;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    int len = strlen(str);
    if(str[len - 1] == '\n')
    {
        str[len - 1] = '\0';
        len--;
    }
    for(int i = 0; i < len - 1; i++)
    {
        for(int j = i + 1; j < len; j++)
        {
            if(str[i] > str[j])
            {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
    printf("Sorted string: %s", str);
    return 0;
}
