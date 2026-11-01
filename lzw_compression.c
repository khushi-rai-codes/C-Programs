#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_DICT 4096
#define MAX_INPUT 1000
#define MAX_WORD 1000

typedef struct {
    char word[MAX_WORD];
} DictionaryEntry;

int findCode(DictionaryEntry dictionary[],
             int size, const char *word) {
    for (int i = 0; i < size; i++) {
        if (strcmp(dictionary[i].word, word) == 0)
            return i;
    }

    return -1;
}

int main(void) {
    char input[MAX_INPUT];
    char current[MAX_WORD] = "";
    int output[MAX_INPUT];
    int outputCount = 0;

    DictionaryEntry dictionary[MAX_DICT];
    int dictSize = 256;

    printf("Enter text to compress: ");

    if (!fgets(input, sizeof(input), stdin)) {
        printf("Input error.\n");
        return 1;
    }

    input[strcspn(input, "\n")] = '\0';

    for (int i = 0; i < 256; i++) {
        dictionary[i].word[0] = (char)i;
        dictionary[i].word[1] = '\0';
    }

    for (int i = 0; input[i] != '\0'; i++) {
        char next[MAX_WORD];

        if (strlen(current) + 1 >= MAX_WORD) {
            printf("Input sequence too long.\n");
            return 1;
        }

        strcpy(next, current);
        int length = (int)strlen(next);
        next[length] = input[i];
        next[length + 1] = '\0';

        if (findCode(dictionary, dictSize, next) != -1) {
            strcpy(current, next);
        } else {
            int code = findCode(dictionary, dictSize, current);

            if (code == -1) {
                printf("Compression error.\n");
                return 1;
            }

            output[outputCount++] = code;

            if (dictSize < MAX_DICT) {
                strcpy(dictionary[dictSize++].word, next);
            }

            current[0] = input[i];
            current[1] = '\0';
        }
    }

    if (current[0] != '\0') {
        int code = findCode(dictionary, dictSize, current);
        output[outputCount++] = code;
    }

    printf("\nCompressed codes:\n");

    for (int i = 0; i < outputCount; i++)
        printf("%d ", output[i]);

    printf("\n\nOriginal length: %zu bytes\n", strlen(input));
    printf("Compressed code count: %d\n", outputCount);

    return 0;
}
