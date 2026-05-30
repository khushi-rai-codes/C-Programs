#include<stdio.h>
struct Student
{
    int roll;
    char name[50];
};
struct Student students[100];
int count = 0;
void addStudent()
{
    printf("Enter Roll Number: ");
    scanf("%d", &students[count].roll);
    printf("Enter Name: ");
    scanf(" %[^\n]", students[count].name);
    count++;
    printf("Student Added Successfully\n");
}
void displayStudents()
{
    if(count == 0)
    {
        printf("No Students Found\n");
        return;
    }
    for(int i = 0; i < count; i++)
    {
        printf("\nRoll: %d", students[i].roll);
        printf("\nName: %s\n", students[i].name);
    }
}
void searchStudent()
{
    int roll;
    printf("Enter Roll Number: ");
    scanf("%d", &roll);
    for(int i = 0; i < count; i++)
    {
        if(students[i].roll == roll)
        {
            printf("Student Found\n");
            printf("Name: %s\n", students[i].name);
            return;
        }
    }
    printf("Student Not Found\n");
}
int main()
{
    int choice;
    do
    {
        printf("\n1. Add Student");
        printf("\n2. Display Students");
        printf("\n3. Search Student");
        printf("\n4. Exit");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
        }
    } while(choice != 4);
    return 0;
}
