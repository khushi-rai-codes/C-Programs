#include <stdio.h>

#define MAX 20

void readPolynomial(int poly[], int degree) {
    for (int i = degree; i >= 0; i--) {
        printf("Coefficient of x^%d: ", i);
        scanf("%d", &poly[i]);
    }
}

void displayPolynomial(int poly[], int degree) {
    int first = 1;

    for (int i = degree; i >= 0; i--) {
        if (poly[i] == 0)
            continue;

        if (!first) {
            if (poly[i] > 0)
                printf(" + ");
            else
                printf(" - ");
        } else if (poly[i] < 0) {
            printf("-");
        }

        int coefficient = poly[i] < 0 ? -poly[i] : poly[i];

        if (i == 0) {
            printf("%d", coefficient);
        } else if (i == 1) {
            if (coefficient != 1)
                printf("%d", coefficient);
            printf("x");
        } else {
            if (coefficient != 1)
                printf("%d", coefficient);
            printf("x^%d", i);
        }

        first = 0;
    }

    if (first)
        printf("0");

    printf("\n");
}

int main() {
    int p[MAX + 1] = {0};
    int q[MAX + 1] = {0};
    int result[2 * MAX + 1] = {0};

    int degree1, degree2;

    printf("Enter degree of first polynomial: ");
    scanf("%d", &degree1);

    if (degree1 < 0 || degree1 > MAX) {
        printf("Invalid degree.\n");
        return 0;
    }

    printf("\nEnter first polynomial:\n");
    readPolynomial(p, degree1);

    printf("\nEnter degree of second polynomial: ");
    scanf("%d", &degree2);

    if (degree2 < 0 || degree2 > MAX) {
        printf("Invalid degree.\n");
        return 0;
    }

    printf("\nEnter second polynomial:\n");
    readPolynomial(q, degree2);

    for (int i = 0; i <= degree1; i++) {
        for (int j = 0; j <= degree2; j++) {
            result[i + j] += p[i] * q[j];
        }
    }

    printf("\nFirst Polynomial: ");
    displayPolynomial(p, degree1);

    printf("Second Polynomial: ");
    displayPolynomial(q, degree2);

    printf("Product: ");
    displayPolynomial(result, degree1 + degree2);

    return 0;
}
