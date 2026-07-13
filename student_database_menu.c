#include <stdio.h>
struct Student
{
    int roll;
    char name[50];
    float marks;
};
int main()
{
    struct Student s[5];
    int n, i;
    printf("Enter number of students (Max 5): ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        printf("\nStudent %d\n", i + 1);
        printf("Roll: ");
        scanf("%d", &s[i].roll);
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Marks: ");
        scanf("%f", &s[i].marks);
    }
    printf("\n----- Student Records -----\n");
    for(i = 0; i < n; i++)
    {
        printf("\nRoll  : %d", s[i].roll);
        printf("\nName  : %s", s[i].name);
        printf("\nMarks : %.2f\n", s[i].marks);
    }
    return 0;
}
