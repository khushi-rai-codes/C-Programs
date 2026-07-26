#include <stdio.h>
#include <ctype.h>
int main()
{
    FILE *fp;
    char ch;
    int words = 0, inWord = 0;
    fp = fopen("sample.txt", "r");
    if (fp == NULL)
    {
        printf("Unable to open file.\n");
        return 1;
    }
    while ((ch = fgetc(fp)) != EOF)
    {
        if (isspace(ch))
        {
            inWord = 0;
        }
        else if (!inWord)
        {
            words++;
            inWord = 1;
        }
    }
    fclose(fp);
    printf("Total Words = %d\n", words);
    return 0;
}
