#include<stdio.h>
struct Employee
{
    int id;
    char name[50];
    float salary;
};
struct Employee emp[100];
int count = 0;
void addEmployee()
{
    printf("Enter Employee ID: ");
    scanf("%d", &emp[count].id);
    printf("Enter Employee Name: ");
    scanf(" %[^\n]", emp[count].name);
    printf("Enter Salary: ");
    scanf("%f", &emp[count].salary);
    count++;
    printf("Employee Added Successfully\n");
}
void displayEmployees()
{
    if(count == 0)
    {
        printf("No Employees Found\n");
        return;
    }
    for(int i = 0; i < count; i++)
    {
        printf("\nID: %d", emp[i].id);
        printf("\nName: %s", emp[i].name);
        printf("\nSalary: %.2f\n", emp[i].salary);
    }
}
void searchEmployee()
{
    int id;
    printf("Enter Employee ID: ");
    scanf("%d", &id);
    for(int i = 0; i < count; i++)
    {
        if(emp[i].id == id)
        {
            printf("Employee Found\n");
            printf("Name: %s\n", emp[i].name);
            printf("Salary: %.2f\n", emp[i].salary);
            return;
        }
    }
    printf("Employee Not Found\n");
}
int main()
{
    int choice;
    do
    {
        printf("\n1. Add Employee");
        printf("\n2. Display Employees");
        printf("\n3. Search Employee");
        printf("\n4. Exit");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: searchEmployee(); break;
        }
    } while(choice != 4);
    return 0;
}
