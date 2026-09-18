#include <stdio.h>

#define MAX_EXPENSES 100

struct Expense
{
    char category[30];
    float amount;
};

int main()
{
    struct Expense expenses[MAX_EXPENSES];

    int count = 0;
    int choice;
    float total;

    while (1)
    {
        printf("\n===== EXPENSE TRACKER =====\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Show Total\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:

                if (count >= MAX_EXPENSES)
                {
                    printf("Expense limit reached.\n");
                    break;
                }

                printf("Enter Category: ");
                scanf("%29s",
                      expenses[count].category);

                printf("Enter Amount: ");
                scanf("%f",
                      &expenses[count].amount);

                if (expenses[count].amount < 0)
                {
                    printf("Amount cannot be negative.\n");
                    break;
                }

                count++;

                printf("Expense added successfully.\n");

                break;

            case 2:

                if (count == 0)
                {
                    printf("No expenses recorded.\n");
                    break;
                }

                printf("\n----- EXPENSES -----\n");

                for (int i = 0; i < count; i++)
                {
                    printf(
                        "%d. %s - %.2f\n",
                        i + 1,
                        expenses[i].category,
                        expenses[i].amount
                    );
                }

                break;

            case 3:

                total = 0;

                for (int i = 0; i < count; i++)
                    total += expenses[i].amount;

                printf(
                    "Total Expenses: %.2f\n",
                    total
                );

                break;

            case 4:

                printf("Exiting Expense Tracker.\n");
                return 0;

            default:

                printf("Invalid choice.\n");
        }
    }
}
