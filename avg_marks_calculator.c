#include<stdio.h>
int main()
{
    int marks1, marks2, marks3;
    float average;

    printf("Enter marks of 3 subjects:\n");
    scanf("%d %d %d", &marks1, &marks2, &marks3);

    average = (marks1 + marks2 + marks3) / 3.0;

    printf("Average Marks = %.2f", average);

    return 0;
}
