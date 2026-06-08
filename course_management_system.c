#include<stdio.h>
struct Course
{
    int id;
    char name[50];
};
struct Course courses[100];
int count = 0;
void addCourse()
{
    printf("Enter Course ID: ");
    scanf("%d", &courses[count].id);
    printf("Enter Course Name: ");
    scanf(" %[^\n]", courses[count].name);
    count++;
    printf("Course Added Successfully\n");
}
void displayCourses()
{
    if(count == 0)
    {
        printf("No Courses Found\n");
        return;
    }
    for(int i = 0; i < count; i++)
    {
        printf("\nID: %d", courses[i].id);
        printf("\nName: %s\n", courses[i].name);
    }
}
void searchCourse()
{
    int id;
    printf("Enter Course ID: ");
    scanf("%d", &id);
    for(int i = 0; i < count; i++)
    {
        if(courses[i].id == id)
        {
            printf("Course Found\n");
            printf("Name: %s\n", courses[i].name);
            return;
        }
    }
    printf("Course Not Found\n");
}
int main()
{
    int choice;
    do
    {
        printf("\n1. Add Course");
        printf("\n2. Display Courses");
        printf("\n3. Search Course");
        printf("\n4. Exit");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: addCourse(); break;
            case 2: displayCourses(); break;
            case 3: searchCourse(); break;
        }
    } while(choice != 4);
    return 0;
}
