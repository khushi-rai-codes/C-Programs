#include <stdio.h>
#include <string.h>

#define MAX_DATA 100

int isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

int main(void) {
    char input[MAX_DATA];
    int code[2 * MAX_DATA] = {0};
    int n, parityBits = 0;

    printf("Enter binary data: ");

    if (scanf("%99s", input) != 1) {
        printf("Input error.\n");
        return 1;
    }

    n = (int)strlen(input);

    if (n == 0 || n >= MAX_DATA) {
        printf("Invalid data length.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        if (input[i] != '0' && input[i] != '1') {
            printf("Only binary digits are allowed.\n");
            return 1;
        }
    }

    while ((1 << parityBits) < n + parityBits + 1)
        parityBits++;

    int total = n + parityBits;
    int dataIndex = 0;

    for (int i = 1; i <= total; i++) {
        if (!isPowerOfTwo(i))
            code[i] = input[dataIndex++] - '0';
    }

    for (int p = 1; p <= total; p *= 2) {
        int parity = 0;

        for (int i = 1; i <= total; i++) {
            if (i & p)
                parity ^= code[i];
        }

        code[p] = parity;
    }

    printf("\nEncoded Hamming code: ");

    for (int i = total; i >= 1; i--)
        printf("%d", code[i]);

    printf("\n");

    int errorPosition;

    printf("\nEnter simulated error position (0 for none): ");

    if (scanf("%d", &errorPosition) != 1 ||
        errorPosition < 0 || errorPosition > total) {
        printf("Invalid error position.\n");
        return 1;
    }

    if (errorPosition != 0)
        code[errorPosition] ^= 1;

    int syndrome = 0;

    for (int p = 1; p <= total; p *= 2) {
        int parity = 0;

        for (int i = 1; i <= total; i++) {
            if (i & p)
                parity ^= code[i];
        }

        if (parity)
            syndrome += p;
    }

    if (syndrome == 0) {
        printf("No error detected.\n");
    } else if (syndrome <= total) {
        printf("Error detected at position: %d\n", syndrome);

        code[syndrome] ^= 1;

        printf("Corrected code: ");

        for (int i = total; i >= 1; i--)
            printf("%d", code[i]);

        printf("\n");
    } else {
        printf("Invalid syndrome; error cannot be corrected.\n");
    }

    printf("Recovered data: ");

    for (int i = 1; i <= total; i++) {
        if (!isPowerOfTwo(i))
            printf("%d", code[i]);
    }

    printf("\n");

    return 0;
}
