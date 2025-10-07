#include <stdio.h>
#include <string.h> // For strcpy

// Define the BankAccount structure
struct BankAccount {
    int accountNumber;
    char accountHolderName[50];
    double balance;
};

int main() {
    struct BankAccount myAccount;
    int choice;
    double amount;

    // Initialize account details (for demonstration purposes)
    myAccount.accountNumber =2137;
    strcpy(myAccount.accountHolderName, "Veena Shinde");
    myAccount.balance = 10000.00;

    printf("Welcome to the Bank Management System!\n");

    do {
        printf("\n--- Menu ---\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. View Account Details\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter amount to deposit: ");
                scanf("%lf", &amount);
                if (amount > 0) {
                    myAccount.balance += amount;
                    printf("Deposit successful. New balance: %.2lf\n", myAccount.balance);
                } else {
                    printf("Invalid deposit amount.\n");
                }
                break;
            case 2:
                printf("Enter amount to withdraw: ");
                scanf("%lf", &amount);
                if (amount > 0 && amount <= myAccount.balance) {
                    myAccount.balance -= amount;
                    printf("Withdrawal successful. New balance: %.2lf\n", myAccount.balance);
                } else if (amount > myAccount.balance) {
                    printf("Insufficient balance.\n");
                } else {
                    printf("Invalid withdrawal amount.\n");
                }
                break;
            case 3:
                printf("\n--- Account Details ---\n");
                printf("Account Number: %d\n", myAccount.accountNumber);
                printf("Account Holder: %s\n", myAccount.accountHolderName);
                printf("Current Balance: %.2lf\n", myAccount.balance);
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}