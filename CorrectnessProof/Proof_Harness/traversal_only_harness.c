void proof_harness() {
    struct Account *from;
    struct Account *to;
    int amount;
    CPROVER_assume(from->bal >= 0);
    CPROVER_assume(to->bal >= 0);
    CPROVER_assume(amount > 0);
    CPROVER_assume(from->bal >= amount);

    // Save the initial balances for verification
    unsigned short initial_from_balance = from->bal;
    unsigned short initial_to_balance = to->bal;
    transfer(from, to, amount);

    // Check that the new balances are the expected values after transfer
    assert(from->bal == initial_from_balance - amount);
    assert(to->bal == initial_to_balance + amount);
}