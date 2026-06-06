#include<stdio.h>
struct Book
{
    int id;
    char title[50];
    int issued;
};
struct Book books[100];
int count = 0;
void addBook()
{
    printf("Enter Book ID: ");
    scanf("%d", &books[count].id);
    printf("Enter Book Title: ");
    scanf(" %[^\n]", books[count].title);
    books[count].issued = 0;
    count++;
    printf("Book Added Successfully\n");
}
void displayBooks()
{
    for(int i = 0; i < count; i++)
    {
        printf("\nID: %d", books[i].id);
        printf("\nTitle: %s", books[i].title);
        printf("\nStatus: %s\n",
               books[i].issued ? "Issued" : "Available");
    }
}
void issueBook()
{
    int id;
    printf("Enter Book ID: ");
    scanf("%d", &id);
    for(int i = 0; i < count; i++)
    {
        if(books[i].id == id)
        {
            books[i].issued = 1;
            printf("Book Issued\n");
            return;
        }
    }
    printf("Book Not Found\n");
}
void returnBook()
{
    int id;
    printf("Enter Book ID: ");
    scanf("%d", &id);
    for(int i = 0; i < count; i++)
    {
        if(books[i].id == id)
        {
            books[i].issued = 0;
            printf("Book Returned\n");
            return;
        }
    }
    printf("Book Not Found\n");
}
int main()
{
    int choice;
    do
    {
        printf("\n1. Add Book");
        printf("\n2. Display Books");
        printf("\n3. Issue Book");
        printf("\n4. Return Book");
        printf("\n5. Exit");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: issueBook(); break;
            case 4: returnBook(); break;
        }
    } while(choice != 5);
    return 0;
}
