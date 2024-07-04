void proof_harness() {
    node *root = NULL;
    int data;
    CPROVER_assume(data >= 0);
    CPROVER_assume(data <= 100);
    insert_bt(&root, data);
    
}