#include<stdio.h>
struct Account
{
    int accountNumber;
    float balance;
};
int main()
{
    struct Account acc;
    int choice;
    float amount;
    printf("Enter Account Number: ");
    scanf("%d", &acc.accountNumber);
    acc.balance = 0;
    do
    {
        printf("\n1. Deposit");
        printf("\n2. Withdraw");
        printf("\n3. Check Balance");
        printf("\n4. Exit");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter Amount: ");
                scanf("%f", &amount);
                acc.balance += amount;
                break;
            case 2:
                printf("Enter Amount: ");
                scanf("%f", &amount);
                if(amount <= acc.balance)
                    acc.balance -= amount;
                else
                    printf("Insufficient Balance\n");
                break;
            case 3:
                printf("Balance = %.2f\n", acc.balance);
                break;
        }
    } while(choice != 4);
    return 0;
}
