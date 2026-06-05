#include<stdio.h>
struct Passenger
{
    int id;
    char name[50];
};
struct Passenger passengers[100];
int count = 0;
void bookTicket()
{
    printf("Enter Passenger ID: ");
    scanf("%d", &passengers[count].id);
    printf("Enter Passenger Name: ");
    scanf(" %[^\n]", passengers[count].name);
    count++;
    printf("Ticket Booked Successfully\n");
}
void displayReservations()
{
    if(count == 0)
    {
        printf("No Reservations Found\n");
        return;
    }
    for(int i = 0; i < count; i++)
    {
        printf("\nID: %d", passengers[i].id);
        printf("\nName: %s\n", passengers[i].name);
    }
}
void searchPassenger()
{
    int id;
    printf("Enter Passenger ID: ");
    scanf("%d", &id);
    for(int i = 0; i < count; i++)
    {
        if(passengers[i].id == id)
        {
            printf("Passenger Found\n");
            printf("Name: %s\n", passengers[i].name);
            return;
        }
    }
    printf("Passenger Not Found\n");
}
void cancelTicket()
{
    int id;
    printf("Enter Passenger ID to Cancel: ");
    scanf("%d", &id);
    for(int i = 0; i < count; i++)
    {
        if(passengers[i].id == id)
        {
            for(int j = i; j < count - 1; j++)
            {
                passengers[j] = passengers[j + 1];
            }
            count--;
            printf("Reservation Cancelled\n");
            return;
        }
    }
    printf("Passenger Not Found\n");
}
int main()
{
    int choice;
    do
    {
        printf("\n1. Book Ticket");
        printf("\n2. View Reservations");
        printf("\n3. Search Passenger");
        printf("\n4. Cancel Ticket");
        printf("\n5. Exit");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: bookTicket(); break;
            case 2: displayReservations(); break;
            case 3: searchPassenger(); break;
            case 4: cancelTicket(); break;
        }
    } while(choice != 5);
    return 0;
}
