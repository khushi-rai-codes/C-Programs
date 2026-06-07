#include<stdio.h>
struct Guest
{
    int room;
    char name[50];
};
struct Guest guests[100];
int count = 0;
void bookRoom()
{
    printf("Enter Room Number: ");
    scanf("%d", &guests[count].room);
    printf("Enter Guest Name: ");
    scanf(" %[^\n]", guests[count].name);
    count++;
    printf("Room Booked Successfully\n");
}
void displayGuests()
{
    if(count == 0)
    {
        printf("No Guests Found\n");
        return;
    }
    for(int i = 0; i < count; i++)
    {
        printf("\nRoom: %d", guests[i].room);
        printf("\nGuest: %s\n", guests[i].name);
    }
}
void checkoutGuest()
{
    int room;
    printf("Enter Room Number: ");
    scanf("%d", &room);
    for(int i = 0; i < count; i++)
    {
        if(guests[i].room == room)
        {
            for(int j = i; j < count - 1; j++)
                guests[j] = guests[j + 1];
            count--;
            printf("Guest Checked Out\n");
            return;
        }
    }
    printf("Room Not Found\n");
}
int main()
{
    int choice;
    do
    {
        printf("\n1. Book Room");
        printf("\n2. View Guests");
        printf("\n3. Check Out");
        printf("\n4. Exit");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: bookRoom(); break;
            case 2: displayGuests(); break;
            case 3: checkoutGuest(); break;
        }
    } while(choice != 4);
    return 0;
}
