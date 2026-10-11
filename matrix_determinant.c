#include <stdio.h>
#include <math.h>

#define MAX 100
#define EPSILON 1e-12

double determinant(double matrix[MAX][MAX], int n) {
    double det = 1.0;
    int sign = 1;

    for (int col = 0; col < n; col++) {
        int pivot = col;

        for (int row = col + 1; row < n; row++) {
            if (fabs(matrix[row][col]) >
                fabs(matrix[pivot][col])) {
                pivot = row;
            }
        }

        if (fabs(matrix[pivot][col]) < EPSILON)
            return 0.0;

        if (pivot != col) {
            for (int j = 0; j < n; j++) {
                double temp = matrix[col][j];
                matrix[col][j] = matrix[pivot][j];
                matrix[pivot][j] = temp;
            }

            sign = -sign;
        }

        double pivotValue = matrix[col][col];
        det *= pivotValue;

        for (int row = col + 1; row < n; row++) {
            double factor = matrix[row][col] / pivotValue;

            for (int j = col + 1; j < n; j++)
                matrix[row][j] -= factor * matrix[col][j];

            matrix[row][col] = 0.0;
        }
    }

    return sign * det;
}

int main(void) {
    double matrix[MAX][MAX];
    int n;

    printf("Enter matrix dimension (1-%d): ", MAX);

    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid dimension.\n");
        return 1;
    }

    printf("Enter the %d x %d matrix:\n", n, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (scanf("%lf", &matrix[i][j]) != 1 ||
                !isfinite(matrix[i][j])) {
                printf("Invalid matrix value.\n");
                return 1;
            }
        }
    }

    double result = determinant(matrix, n);

    if (fabs(result) < EPSILON)
        result = 0.0;

    printf("Determinant: %.6f\n", result);

    return 0;
}
