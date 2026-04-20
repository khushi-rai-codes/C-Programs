#include <stdio.h>
void fibonacciSeries(int n) {
    int a = 0, b = 1;
    for (int i = 0; i < n; i++) {
        printf("%d ", a);
        int next = a + b;
        a = b;
        b = next;
    }
}

int main() {
    int n;

    printf("Enter the number of terms: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Please enter a positive number.");
    } else {
        printf("Fibonacci Series:\n");
        fibonacciSeries(n);
    }
    return 0;
}
