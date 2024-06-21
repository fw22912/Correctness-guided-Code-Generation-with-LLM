#include <assert.h> // for assert
#include <stdlib.h> // for malloc

struct Account {
    unsigned short bal;
};

// Function to withdraw an amount from an account
void withdraw(struct Account *account, unsigned short amount) {
    unsigned short de = account->bal;
    account->bal = de - amount;
}

void proof_harness_withdraw() {
    struct Account *account = (struct Account *)malloc(sizeof(struct Account));
    unsigned short amount;

    // Assuming proper initialization of account and amount
    __CPROVER_assume(account != NULL);
    __CPROVER_assume(account->bal >= 0);
    __CPROVER_assume(amount > 0);
    __CPROVER_assume(account->bal >= amount);

    // Save the initial balance for verification
    unsigned short initial_balance = account->bal;

    withdraw(account, amount);

    // Check that the new balance is the expected value after withdrawal
    assert(account->bal == initial_balance - amount);

    free(account); // Free the allocated memory
}