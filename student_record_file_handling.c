#include <stdio.h>
struct Student
{
    int roll;
    char name[50];
    float marks;
};
int main()
{
    struct Student s;
    FILE *fp;
    fp = fopen("students.txt", "a");
    if (fp == NULL)
    {
        printf("Unable to open file.");
        return 1;
    }
    printf("Enter Roll Number: ");
    scanf("%d", &s.roll);
    printf("Enter Name: ");
    scanf("%s", s.name);
    printf("Enter Marks: ");
    scanf("%f", &s.marks);
    fprintf(fp, "%d %s %.2f\n", s.roll, s.name, s.marks);
    fclose(fp);
    printf("Record saved successfully.\n");
    return 0;
}
