#include <stdio.h>
#include <conio.h>

struct Account
{
    int accountNumber;
    char name[50];
    float balance;
};

int createAccount(struct Account *acc);
void displayAccount(struct Account *acc);
void depositMoney(struct Account *acc);
void withdrawMoney(struct Account *acc);
void checkBalance(struct Account *acc);

int main()
{
    struct Account acc;
    int choice, accountCreated = 0;

    do
    {
        printf("\n--- Bank Management System ---");
        printf("\n1. Create");
        printf("\n2. Display");
        printf("\n3. Deposit");
        printf("\n4. Withdraw");
        printf("\n5. Balance");
        printf("\n6. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                accountCreated = createAccount(&acc);
                break;

            case 2:
                if(accountCreated)
                    displayAccount(&acc);
                else
                    printf("\nCreate account first!");
                break;

            case 3:
                if(accountCreated)
                    depositMoney(&acc);
                else
                    printf("\nCreate account first!");
                break;

            case 4:
                if(accountCreated)
                    withdrawMoney(&acc);
                else
                    printf("\nCreate account first!");
                break;

            case 5:
                if(accountCreated)
                    checkBalance(&acc);
                else
                    printf("\nCreate account first!");
                break;

            case 6:
                printf("\nThank you!");
                break;

            default:
                printf("\nInvalid choice!");
        }
    } while(choice != 6);

    getch();
    return 0;
}

int createAccount(struct Account *acc)
{
    printf("\nAccount Number: ");
    scanf("%d", &acc->accountNumber);

    printf("Name: ");
    scanf("%s", acc->name);

    printf("Initial Balance: ");
    scanf("%f", &acc->balance);

    if(acc->balance < 0)
    {
        printf("\nInvalid balance!");
        return 0;
    }

    printf("\nAccount Created Successfully!");
    return 1;
}

void displayAccount(struct Account *acc)
{
    printf("\nAccount Number: %d", acc->accountNumber);
    printf("\nName: %s", acc->name);
    printf("\nBalance: %.2f", acc->balance);
}

void depositMoney(struct Account *acc)
{
    float amount;

    printf("\nDeposit amount: ");
    scanf("%f", &amount);

    if(amount > 0)
    {
        acc->balance += amount;
        printf("\nNew Balance: %.2f", acc->balance);
    }
    else
        printf("\nInvalid amount!");
}

void withdrawMoney(struct Account *acc)
{
    float amount;

    printf("\nWithdraw amount: ");
    scanf("%f", &amount);

    if(amount > 0 && amount <= acc->balance)
    {
        acc->balance -= amount;
        printf("\nRemaining Balance: %.2f", acc->balance);
    }
    else
        printf("\nInvalid amount or Insufficient Balance!");
}

void checkBalance(struct Account *acc)
{
    printf("\nAccount Number: %d", acc->accountNumber);
    printf("\nName: %s", acc->name);
    printf("\nCurrent Balance: %.2f", acc->balance);
}
