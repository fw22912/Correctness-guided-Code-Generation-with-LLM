void proof_harness() {
    struct node *src;
    struct node *dest;
    int amount;
    CPROVER_assume(src != NULL);
    CPROVER_assume(dest != NULL);
    CPROVER_assume(amount > 0);
    CPROVER_assume(src->data >= amount);

    int src_initial_balance = src->data;
    int dest_initial_balance = dest->data;
    transfer(src, dest, amount);
    assert(src->data == src_initial_balance - amount);
    assert(dest->data == dest_initial_balance + amount);
}