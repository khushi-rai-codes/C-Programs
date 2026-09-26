#include <stdio.h>

#define MAX_DEGREE 20

void readPolynomial(int poly[], int degree) {
    for (int i = degree; i >= 0; i--) {
        printf("Enter coefficient of x^%d: ", i);
        scanf("%d", &poly[i]);
    }
}

void displayPolynomial(int poly[], int degree) {
    int first = 1;

    for (int i = degree; i >= 0; i--) {
        if (poly[i] == 0) {
            continue;
        }

        if (!first && poly[i] > 0) {
            printf(" + ");
        } else if (poly[i] < 0) {
            if (!first) {
                printf(" - ");
            } else {
                printf("-");
            }
        }

        int coefficient = poly[i] < 0 ? -poly[i] : poly[i];

        if (i == 0) {
            printf("%d", coefficient);
        } else if (i == 1) {
            if (coefficient != 1) {
                printf("%d", coefficient);
            }
            printf("x");
        } else {
            if (coefficient != 1) {
                printf("%d", coefficient);
            }
            printf("x^%d", i);
        }

        first = 0;
    }

    if (first) {
        printf("0");
    }

    printf("\n");
}

int main() {
    int poly1[MAX_DEGREE + 1] = {0};
    int poly2[MAX_DEGREE + 1] = {0};
    int result[MAX_DEGREE + 1] = {0};
    int degree1, degree2;
    int maxDegree;

    printf("Enter degree of first polynomial: ");
    scanf("%d", &degree1);

    if (degree1 < 0 || degree1 > MAX_DEGREE) {
        printf("Invalid degree.\n");
        return 0;
    }

    printf("\nEnter first polynomial coefficients:\n");
    readPolynomial(poly1, degree1);

    printf("\nEnter degree of second polynomial: ");
    scanf("%d", &degree2);

    if (degree2 < 0 || degree2 > MAX_DEGREE) {
        printf("Invalid degree.\n");
        return 0;
    }

    printf("\nEnter second polynomial coefficients:\n");
    readPolynomial(poly2, degree2);

    maxDegree = degree1 > degree2 ? degree1 : degree2;

    for (int i = 0; i <= maxDegree; i++) {
        result[i] = poly1[i] + poly2[i];
    }

    printf("\nFirst Polynomial: ");
    displayPolynomial(poly1, degree1);

    printf("Second Polynomial: ");
    displayPolynomial(poly2, degree2);

    printf("Sum: ");
    displayPolynomial(result, maxDegree);

    return 0;
}
