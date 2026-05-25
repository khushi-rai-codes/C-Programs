#include<stdio.h>
int main()
{
    float marks, percentage;
    printf("Enter marks out of 100: ");
    scanf("%f", &marks);
    percentage = marks;
    printf("Percentage = %.2f\n", percentage);
    if(percentage >= 90)
        printf("Grade A");
    else if(percentage >= 75)
        printf("Grade B");
    else if(percentage >= 60)
        printf("Grade C");
    else if(percentage >= 40)
        printf("Grade D");
    else
        printf("Fail");
    return 0;
}
