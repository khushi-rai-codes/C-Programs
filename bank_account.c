#include <stdio.h>
struct Account
{
    int accountNumber;
    char name[50];
    double balance;
};
void deposit(struct Account *account, double amount)
{
    if (amount > 0)
    {
        account->balance += amount;
        printf("Amount deposited successfully.\n");
    }
    else
    {
        printf("Invalid amount.\n");
    }
}
void withdraw(struct Account *account, double amount)
{
    if (amount <= 0)
    {
        printf("Invalid amount.\n");
    }
    else if (amount > account->balance)
    {
        printf("Insufficient balance.\n");
    }
    else
    {
        account->balance -= amount;
        printf("Amount withdrawn successfully.\n");
    }
}
void displayAccount(struct Account account)
{
    printf("\n----- Account Details -----\n");
    printf("Account Number : %d\n", account.accountNumber);
    printf("Name           : %s\n", account.name);
    printf("Balance        : %.2f\n", account.balance);
int main()
{
    struct Account account;
    int choice;
    double amount;
    printf("Enter Account Number: ");
    scanf("%d", &account.accountNumber);
    printf("Enter Account Holder Name: ");
    scanf("%49s", account.name);
    printf("Enter Initial Balance: ");
    scanf("%lf", &account.balance);
    while (1)
    {
        printf("\n===== BANK MENU =====\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Display Account\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter amount to deposit: ");
                scanf("%lf", &amount);
                deposit(&account, amount);
                break;
            case 2:
                printf("Enter amount to withdraw: ");
                scanf("%lf", &amount);
                withdraw(&account, amount);
                break;
            case 3:
                displayAccount(account);
                break;
            case 4:
                printf("Thank you for using the bank system.\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}
