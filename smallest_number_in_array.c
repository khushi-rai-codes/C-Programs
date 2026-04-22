#include<stdio.h>
int main()
{
    int arr[5], smallest, i;
    printf("Enter 5 numbers:\n");
    for(i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
    }
    smallest = arr[0];
    for(i = 1; i < 5; i++)
    {
        if(arr[i] < smallest)
        {
            smallest = arr[i];
        }
    }
    printf("Smallest number = %d", smallest);

    return 0;
}
