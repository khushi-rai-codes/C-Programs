#include <stdio.h>
struct Employee
{
    int id;
    char name[50];
    float salary;
};
int main()
{
    FILE *file;
    struct Employee employee;
    int n;
    file = fopen("employees.dat", "wb");
    if (file == NULL)
    {
        printf("Unable to create file.\n");
        return 1;
    }
    printf("Enter number of employees: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("\nEmployee %d\n", i + 1);
        printf("Enter ID: ");
        scanf("%d", &employee.id);
        printf("Enter Name: ");
        scanf("%49s", employee.name);
        printf("Enter Salary: ");
        scanf("%f", &employee.salary);
        fwrite(&employee, sizeof(struct Employee), 1, file);
    }
    fclose(file);
  file = fopen("employees.dat", "rb");
    if (file == NULL)
    {
        printf("Unable to read file.\n");
        return 1;
    }
    printf("\n----- Employee Records -----\n");
    while (fread(&employee, sizeof(struct Employee), 1, file) == 1)
    {
        printf("ID     : %d\n", employee.id);
        printf("Name   : %s\n", employee.name);
        printf("Salary : %.2f\n\n", employee.salary);
    }
    fclose(file);
    return 0;
}
