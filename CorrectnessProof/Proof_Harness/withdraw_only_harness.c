void proof_harness_withdraw() {
    struct Account *account = (struct Account *)malloc(sizeof(struct Account));
    __CPROVER_assume(account != NULL);  // Ensure account is not NULL

    unsigned short amount;

    __CPROVER_assume(account->bal >= 0);
    __CPROVER_assume(amount > 0);
    __CPROVER_assume(account->bal >= amount);

    unsigned short initial_balance = account->bal;

    withdraw(account, amount);
    assert(account->bal == initial_balance - amount);

    free(account);
}

