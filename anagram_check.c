#include<stdio.h>
#include<string.h>
int main()
{
    char str1[100], str2[100];
    int freq[256] = {0};
    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);
    str1[strcspn(str1, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';
    if(strlen(str1) != strlen(str2))
    {
        printf("Not Anagrams");
        return 0;
    }
    for(int i = 0; str1[i] != '\0'; i++)
        freq[(int)str1[i]]++;
    for(int i = 0; str2[i] != '\0'; i++)
        freq[(int)str2[i]]--;
    for(int i = 0; i < 256; i++)
    {
        if(freq[i] != 0)
        {
            printf("Not Anagrams");
            return 0;
        }
    }
    printf("Anagrams");
    return 0;
}
