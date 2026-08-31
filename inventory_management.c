#include <stdio.h>
#define MAX_ITEMS 100
struct Item
{
    int id;
    char name[50];
    int quantity;
    float price;
};
void addItem(struct Item items[], int *count)
{
    if (*count >= MAX_ITEMS)
    {
        printf("Inventory is full.\n");
        return;
    }
    printf("Enter Item ID: ");
    scanf("%d", &items[*count].id);
    printf("Enter Item Name: ");
    scanf("%49s", items[*count].name);
    printf("Enter Quantity: ");
    scanf("%d", &items[*count].quantity);
    printf("Enter Price: ");
    scanf("%f", &items[*count].price);
    (*count)++;
    printf("Item added successfully.\n");
}
void displayItems(struct Item items[], int count)
{
    if (count == 0)
    {
        printf("Inventory is empty.\n");
        return;
    }
    printf("\n===== INVENTORY =====\n");
    for (int i = 0; i < count; i++)
    {
        printf(
            "ID: %d | Name: %s | Quantity: %d | Price: %.2f\n",
            items[i].id,
            items[i].name,
            items[i].quantity,
            items[i].price
        );
    }
}
void searchItem(struct Item items[], int count)
{
    int id;
    int found = 0;
    printf("Enter Item ID to search: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++)
    {
        if (items[i].id == id)
        {
            printf("\nItem Found\n");
            printf("Name: %s\n", items[i].name);
            printf("Quantity: %d\n", items[i].quantity);
            printf("Price: %.2f\n", items[i].price);

            found = 1;
            break;
        }
    }
    if (!found)
        printf("Item not found.\n");
}
int main()
{
    struct Item items[MAX_ITEMS];
    int count = 0;
    int choice;
    while (1)
    {
        printf("\n===== INVENTORY MANAGEMENT =====\n");
        printf("1. Add Item\n");
        printf("2. Display Items\n");
        printf("3. Search Item\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                addItem(items, &count);
                break;
            case 2:
                displayItems(items, count);
                break;
            case 3:
                searchItem(items, count);
                break;
            case 4:
                printf("Program ended.\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}
