#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

void compress(const char *input, char *output) {
    int i = 0;
    int j = 0;

    while (input[i] != '\0') {
        char current = input[i];
        int count = 0;

        while (input[i] == current) {
            count++;
            i++;
        }

        j += sprintf(output + j, "%c%d", current, count);
    }

    output[j] = '\0';
}

int main(void) {
    char input[MAX_LENGTH];
    char output[MAX_LENGTH * 12];

    printf("Enter a string without spaces: ");

    if (scanf("%999s", input) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    compress(input, output);

    printf("Original string: %s\n", input);
    printf("Compressed string: %s\n", output);

    return 0;
}
