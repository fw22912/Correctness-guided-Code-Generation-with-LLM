void proof_harness() {
    struct node *root = NULL;
    int data1, data2;
    transfer(&root, data1, data2);
    CPROVER_assert(root != NULL, "Root should not be null");
}