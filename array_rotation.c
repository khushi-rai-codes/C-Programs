#include <stdio.h>
int main() {
    int n, d;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]); 
    printf("Enter number of left rotations: ");
    scanf("%d", &d);
    d = d % n;
    printf("Array after rotation:\n");
    for(int i = d; i < n; i++)
        printf("%d ", arr[i]);
    for(int i = 0; i < d; i++)
        printf("%d ", arr[i]);
    return 0;
}
