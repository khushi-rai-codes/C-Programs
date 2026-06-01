#include<stdio.h>
struct Item
{
    int id;
    char name[50];
};
struct Item items[100];
int count = 0;
void addItem()
{
    printf("Enter Item ID: ");
    scanf("%d", &items[count].id);
    printf("Enter Item Name: ");
    scanf(" %[^\n]", items[count].name);
    count++;
    printf("Item Added Successfully\n");
}
void displayItems()
{
    if(count == 0)
    {
        printf("No Items Available\n");
        return;
    }
    for(int i = 0; i < count; i++)
    {
        printf("\nID: %d", items[i].id);
        printf("\nName: %s\n", items[i].name);
    }
}
void searchItem()
{
    int id;
    printf("Enter Item ID: ");
    scanf("%d", &id);
    for(int i = 0; i < count; i++)
    {
        if(items[i].id == id)
        {
            printf("Item Found\n");
            printf("Name: %s\n", items[i].name);
            return;
        }
    }
    printf("Item Not Found\n");
}
int main()
{
    int choice;
    do
    {
        printf("\n1. Add Item");
        printf("\n2. Display Items");
        printf("\n3. Search Item");
        printf("\n4. Exit");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                addItem();
                break;
            case 2:
                displayItems();
                break;
            case 3:
                searchItem();
                break;
        }
    } while(choice != 4);
    return 0;
}
