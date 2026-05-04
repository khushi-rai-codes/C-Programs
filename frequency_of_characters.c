#include<stdio.h>
#include<string.h>
int main()
{
    char str[200];
    int freq[256] = {0};
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] != ' ' && str[i] != '\n')
        {
            freq[(int)str[i]]++;
        }
    }
    printf("Character frequencies:\n");
    for(int i = 0; i < 256; i++)
    {
        if(freq[i] > 0)
        {
            printf("%c = %d\n", i, freq[i]);
        }
    }
    return 0;
}
