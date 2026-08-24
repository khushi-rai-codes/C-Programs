#include <stdio.h>
#define MAX_STUDENTS 100
struct Student
{
    int rollNumber;
    char name[50];
    float marks;
};
void addStudent(struct Student students[], int *count)
{
    if (*count >= MAX_STUDENTS)
    {
        printf("Student limit reached.\n");
        return;
    }
    printf("Enter Roll Number: ");
    scanf("%d", &students[*count].rollNumber);
    printf("Enter Name: ");
    scanf("%49s", students[*count].name);
    printf("Enter Marks: ");
    scanf("%f", &students[*count].marks);
    (*count)++;
    printf("Student added successfully.\n");
}
void displayStudents(struct Student students[], int count)
{
    if (count == 0)
    {
        printf("No student records available.\n");
        return;
    }
    printf("\n----- Student Records -----\n");
    for (int i = 0; i < count; i++)
    {
        printf("\nRoll Number: %d\n",
               students[i].rollNumber);
        printf("Name: %s\n",
               students[i].name);
        printf("Marks: %.2f\n",
               students[i].marks);
    }
}
void searchStudent(struct Student students[], int count)
{
    int roll;
    int found = 0;
    printf("Enter Roll Number to search: ");
    scanf("%d", &roll);
    for (int i = 0; i < count; i++)
    {
        if (students[i].rollNumber == roll)
        {
            printf("\nStudent Found!\n");
            printf("Name: %s\n", students[i].name);
            printf("Marks: %.2f\n", students[i].marks);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("Student not found.\n");
}
int main()
{
    struct Student students[MAX_STUDENTS];
    int count = 0;
    int choice;
    while (1)
    {
        printf("\n===== STUDENT MANAGEMENT =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                searchStudent(students, count);
                break;
            case 4:
                printf("Program ended.\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}
