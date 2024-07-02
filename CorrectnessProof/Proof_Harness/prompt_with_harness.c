// Define the Account structure
struct Account {
    unsigned short bal;
};

// Function to transfer an amount from one account to another
void transfer(struct Account *source, struct Account *dest, unsigned short amount) { 
    source->bal = source->bal - amount;
    dest->bal = dest->bal + amount;
}

void proof_harness() {
    struct Account *source;
    struct Account *dest;
    unsigned short amount;
    CPROVER_assume(source->bal >= 0);
    CPROVER_assume(dest->bal >= 0);
    CPROVER_assume(amount > 0);
    CPROVER_assume(source->bal >= amount);

    // Save the initial balances for verification 
    unsigned short initial_source_balance = source->bal;
    unsigned short initial_dest_balance = dest->bal;
    transfer(source, dest, amount);

    // Check that the new balances are the expected values after transfer
    assert(source->bal == initial_source_balance - amount);
    assert(dest->bal == initial_dest_balance + amount);
}