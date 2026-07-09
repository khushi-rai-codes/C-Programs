#include <stdio.h>
struct Employee {
    int id;
    char name[50];
    float salary;
};
int main() {
    FILE *fp;
    struct Employee e;
    fp = fopen("employee.txt", "w");
    if (fp == NULL) {
        printf("File cannot be opened.");
        return 1;
    }
    printf("Enter Employee ID: ");
    scanf("%d", &e.id);
    printf("Enter Employee Name: ");
    scanf("%s", e.name);
    printf("Enter Salary: ");
    scanf("%f", &e.salary);
    fprintf(fp, "%d %s %.2f\n", e.id, e.name, e.salary);
    fclose(fp);
    printf("Employee record saved successfully.");
    return 0;
}
