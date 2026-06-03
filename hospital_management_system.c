#include<stdio.h>
struct Patient
{
    int id;
    char name[50];
};
struct Patient patients[100];
int count = 0;
void addPatient()
{
    printf("Enter Patient ID: ");
    scanf("%d", &patients[count].id);
    printf("Enter Patient Name: ");
    scanf(" %[^\n]", patients[count].name);
    count++;
    printf("Patient Added Successfully\n");
}
void displayPatients()
{
    if(count == 0)
    {
        printf("No Patients Found\n");
        return;
    }
    for(int i = 0; i < count; i++)
    {
        printf("\nID: %d", patients[i].id);
        printf("\nName: %s\n", patients[i].name);
    }
}
void searchPatient()
{
    int id;

    printf("Enter Patient ID: ");
    scanf("%d", &id);

    for(int i = 0; i < count; i++)
    {
        if(patients[i].id == id)
        {
            printf("Patient Found\n");
            printf("Name: %s\n", patients[i].name);
            return;
        }
    }
    printf("Patient Not Found\n");
}
int main()
{
    int choice;
    do
    {
        printf("\n1. Add Patient");
        printf("\n2. Display Patients");
        printf("\n3. Search Patient");
        printf("\n4. Exit");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: addPatient(); break;
            case 2: displayPatients(); break;
            case 3: searchPatient(); break;
        }
    } while(choice != 4);
    return 0;
}
