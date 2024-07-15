#include <stdio.h>
#include <stdlib.h>

struct Account {
    unsigned short bal;
};

// Function to withdraw an amount from an account
void withdraw(struct Account *account, unsigned short amount) {
    unsigned short de = account->bal;
    account->bal = de - amount;
}
