#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_DIGITS 10000

int main(void) {
    char a[MAX_DIGITS + 1];
    char b[MAX_DIGITS + 1];

    printf("Enter first large integer: ");

    if (scanf("%10000s", a) != 1)
        return 1;

    printf("Enter second large integer: ");

    if (scanf("%10000s", b) != 1)
        return 1;

    int n = strlen(a);
    int m = strlen(b);

    for (int i = 0; i < n; i++) {
        if (!isdigit((unsigned char)a[i])) {
            printf("Invalid first integer.\n");
            return 1;
        }
    }

    for (int i = 0; i < m; i++) {
        if (!isdigit((unsigned char)b[i])) {
            printf("Invalid second integer.\n");
            return 1;
        }
    }

    int *result = calloc(n + m, sizeof(int));

    if (!result) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            int product = (a[i] - '0') * (b[j] - '0');

            int position1 = i + j;
            int position2 = i + j + 1;

            int sum = product + result[position2];

            result[position2] = sum % 10;
            result[position1] += sum / 10;
        }
    }

    int index = 0;

    while (index < n + m - 1 && result[index] == 0)
        index++;

    printf("\nMultiplication Result:\n");

    for (int i = index; i < n + m; i++)
        printf("%d", result[i]);

    printf("\n");

    free(result);

    return 0;
}
