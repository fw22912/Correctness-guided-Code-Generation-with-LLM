void proof_harness() {
    struct node *source = newNode(0);
    struct node *dest = newNode(0);
    int data;
    CPROVER_assume(source->data >= 0);
    CPROVER_assume(dest->data >= 0);
    data = source->data;
    transfer(source, dest);
    assert(dest->data == data);
    assert(source->data == 0);
}