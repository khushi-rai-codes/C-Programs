#include <stdio.h>
#include <string.h>

#define WINDOW_SIZE 32
#define LOOKAHEAD_SIZE 16
#define MAX_TOKENS 1000

typedef struct {
    int offset;
    int length;
    char next;
} Token;

int compress(
    const char *input,
    Token tokens[],
    int *tokenCount
) {
    int n = strlen(input);
    int pos = 0;

    *tokenCount = 0;

    while (pos < n) {
        int bestLength = 0;
        int bestOffset = 0;

        int start = pos - WINDOW_SIZE;

        if (start < 0)
            start = 0;

        for (int j = start; j < pos; j++) {
            int length = 0;

            while (length < LOOKAHEAD_SIZE &&
                   pos + length < n &&
                   input[j + length] == input[pos + length]) {
                length++;
            }

            if (length > bestLength) {
                bestLength = length;
                bestOffset = pos - j;
            }
        }

        Token t;

        t.offset = bestOffset;
        t.length = bestLength;

        if (pos + bestLength < n) {
            t.next = input[pos + bestLength];
            pos += bestLength + 1;
        } else {
            t.next = '\0';
            pos += bestLength;
        }

        tokens[(*tokenCount)++] = t;
    }

    return 1;
}

void decompress(
    Token tokens[],
    int tokenCount,
    char output[]
) {
    int pos = 0;

    for (int i = 0; i < tokenCount; i++) {
        Token t = tokens[i];

        if (t.length > 0) {
            int start = pos - t.offset;

            for (int j = 0; j < t.length; j++) {
                output[pos++] = output[start + j];
            }
        }

        if (t.next != '\0')
            output[pos++] = t.next;
    }

    output[pos] = '\0';
}

int main() {
    char input[] =
        "ABABABABABABABCABCABCABC";

    Token tokens[MAX_TOKENS];
    char output[1000];

    int tokenCount;

    compress(input, tokens, &tokenCount);

    printf("Original Text: %s\n", input);

    printf("\nCompressed Tokens:\n");

    for (int i = 0; i < tokenCount; i++) {
        printf("(%d, %d, ",
               tokens[i].offset,
               tokens[i].length);

        if (tokens[i].next == '\0')
            printf("EOF)\n");
        else
            printf("%c)\n", tokens[i].next);
    }

    decompress(tokens, tokenCount, output);

    printf("\nDecompressed Text: %s\n", output);

    printf("\nCompression Successful: %s\n",
           strcmp(input, output) == 0 ? "Yes" : "No");

    printf("Original Size: %lu bytes\n",
           (unsigned long)strlen(input));

    printf("Token Count: %d\n", tokenCount);

    return 0;
}
