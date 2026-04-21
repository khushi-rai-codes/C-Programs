#include<stdio.h>
int main()
{
    int arr[5], largest, i;
    printf("Enter 5 numbers:\n");
    for(i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
    }
    largest = arr[0];
    for(i = 1; i < 5; i++)
    {
        if(arr[i] > largest)
        {
            largest = arr[i];
        }
    }
    printf("Largest number = %d", largest);

    return 0;
}
