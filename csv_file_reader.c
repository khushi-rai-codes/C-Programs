#include <stdio.h>
int main()
{
    FILE *fp;
    char line[200];
    fp = fopen("students.csv", "r");
    if (fp == NULL)
    {
        printf("Unable to open file.\n");
        return 1;
    }
    printf("CSV File Contents:\n\n");
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        printf("%s", line);
    }
    fclose(fp);
    return 0;
}
