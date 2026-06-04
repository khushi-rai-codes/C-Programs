#include<stdio.h>
int seats[10] = {0};
void displaySeats()
{
    printf("\nSeats:\n");
    for(int i = 0; i < 10; i++)
    {
        printf("Seat %d : %s\n",
               i + 1,
               seats[i] ? "Booked" : "Available");
    }
}
int main()
{
    int choice, seat;
    do
    {
        printf("\n1. View Seats");
        printf("\n2. Book Seat");
        printf("\n3. Cancel Seat");
        printf("\n4. Exit");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                displaySeats();
                break;
            case 2:
                printf("Enter Seat Number (1-10): ");
                scanf("%d", &seat);
                if(seat >= 1 && seat <= 10 && !seats[seat-1])
                {
                    seats[seat-1] = 1;
                    printf("Seat Booked\n");
                }
                else
                {
                    printf("Invalid/Already Booked\n");
                }
                break;
            case 3:
                printf("Enter Seat Number (1-10): ");
                scanf("%d", &seat);
                if(seat >= 1 && seat <= 10 && seats[seat-1])
                {
                    seats[seat-1] = 0;
                    printf("Booking Cancelled\n");
                }
                else
                {
                    printf("Seat Not Booked\n");
                }
                break;
        }
    } while(choice != 4);
    return 0;
}
