void proof_harness() { 
    struct Account *src;
    struct Account *dst;
    int amount;
    CPROVER_assume(src->bal >= 0);
    CPROVER_assume(dst->bal >= 0);
    CPROVER_assume(amount > 0);
    CPROVER_assume(src->bal >= amount);

    // Save the initial balances for verification
    unsigned short src_initial_balance = src->bal;
    unsigned short dst_initial_balance = dst->bal;
    transfer(src, dst, amount);

    // Check that the new balances are the expected values after transfer
    assert(src->bal == src_initial_balance - amount); 
    assert(dst->bal == dst_initial_balance + amount); 
}