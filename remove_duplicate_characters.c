#include <stdio.h>
#include <string.h>
int main()
{
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    int visited[256] = {0};
    printf("String after removing duplicates: ");
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!visited[(unsigned char)str[i]])
        {
            printf("%c", str[i]);
            visited[(unsigned char)str[i]] = 1;
        }
    }
    return 0;
}
