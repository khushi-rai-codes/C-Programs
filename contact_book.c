#include <stdio.h>
#include <string.h>
struct Contact
{
    char name[50];
    char phone[20];
};
int main()
{
    struct Contact contacts[100];
    int count = 0;
    int choice;
    while (1)
    {
        printf("\n===== CONTACT BOOK =====\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("Enter Name: ");
            scanf("%49s", contacts[count].name);
            printf("Enter Phone Number: ");
            scanf("%19s", contacts[count].phone);
            count++;
            printf("Contact added successfully.\n");
        }
        else if (choice == 2)
        {
            if (count == 0)
            {
                printf("No contacts available.\n");
            }
            else
            {
                printf("\n----- Contacts -----\n");
                for (int i = 0; i < count; i++)
                {
                    printf("%d. %s - %s\n",
                           i + 1,
                           contacts[i].name,
                           contacts[i].phone);
                }
            }
        }
        else if (choice == 3)
        {
            char searchName[50];
            int found = 0;
            printf("Enter name to search: ");
            scanf("%49s", searchName);
            for (int i = 0; i < count; i++)
            {
                if (strcmp(contacts[i].name, searchName) == 0)
                {
                    printf("Contact Found!\n");
                    printf("Name : %s\n", contacts[i].name);
                    printf("Phone: %s\n", contacts[i].phone);
                    found = 1;
                    break;
                }
            }
            if (!found)
                printf("Contact not found.\n");
        }
        else if (choice == 4)
        {
            printf("Exiting Contact Book.\n");
            break;
        }
        else
        {
            printf("Invalid choice.\n");
        }
    }
    return 0;
}
