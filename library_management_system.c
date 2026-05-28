#include<stdio.h>
#include<string.h>
char books[100][100];
int count = 0;
void addBook()
{
    printf("Enter book name: ");
    scanf(" %[^\n]", books[count]);
    count++;
    printf("Book added successfully\n");
}
void displayBooks()
{
    if(count == 0)
    {
        printf("No books available\n");
        return;
    }
    printf("Books in Library:\n");
    for(int i = 0; i < count; i++)
    {
        printf("%d. %s\n", i + 1, books[i]);
    }
}
void searchBook()
{
    char name[100];
    int found = 0;
    printf("Enter book name to search: ");
    scanf(" %[^\n]", name);
    for(int i = 0; i < count; i++)
    {
        if(strcmp(name, books[i]) == 0)
        {
            printf("Book Found\n");
            found = 1;
            break;
        }
    }
    if(!found)
        printf("Book Not Found\n");
}
int main()
{
    int choice;
    do
    {
        printf("\n--- LIBRARY MENU ---\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                printf("Exiting Program\n");
                break;
            default:
                printf("Invalid Choice\n");
        }
    } while(choice != 4);
    return 0;
}
