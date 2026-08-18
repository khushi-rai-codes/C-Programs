#include <stdio.h>
#include <ctype.h>
int main()
{
    FILE *file;
    char filename[100];
    char ch;
    int characters = 0;
    int words = 0;
    int lines = 0;
    int inWord = 0;
    printf("Enter file name: ");
    scanf("%99s", filename);
    file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Unable to open file.\n");
        return 1;
    }
    while ((ch = fgetc(file)) != EOF)
    {
        characters++;
        if (ch == '\n')
            lines++;
        if (isspace((unsigned char)ch))
        {
            inWord = 0;
        }
        else if (!inWord)
        {
            words++;
            inWord = 1;
        }
    }
    fclose(file);
    printf("\n----- File Statistics -----\n");
    printf("Characters : %d\n", characters);
    printf("Words      : %d\n", words);
    printf("Lines      : %d\n", lines);
    return 0;
}
