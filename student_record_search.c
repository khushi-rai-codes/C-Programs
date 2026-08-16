#include <stdio.h>
struct Student
{
    int roll;
    char name[50];
    float marks;
};
int main()
{
    struct Student students[100];
    int n, searchRoll;
    int found = 0;
    printf("Enter number of students: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("\nStudent %d\n", i + 1);
        printf("Enter Roll Number: ");
        scanf("%d", &students[i].roll);
        printf("Enter Name: ");
        scanf("%49s", students[i].name);
        printf("Enter Marks: ");
        scanf("%f", &students[i].marks);
    }
    printf("\nEnter Roll Number to Search: ");
    scanf("%d", &searchRoll);
    for (int i = 0; i < n; i++)
    {
        if (students[i].roll == searchRoll)
        {
            printf("\nStudent Found!\n");
            printf("Roll Number: %d\n", students[i].roll);
            printf("Name: %s\n", students[i].name);
            printf("Marks: %.2f\n", students[i].marks);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("Student not found.\n");
    return 0;
}
