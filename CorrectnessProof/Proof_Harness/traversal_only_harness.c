void proof_harness() {
    struct node *node;
    CPROVER_assume(node != NULL);
    inOrderTraversal(node);
    preOrderTraversal(node);
    postOrderTraversal(node);
}