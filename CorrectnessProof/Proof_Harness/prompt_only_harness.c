void proof_harness_main() {
    int result = main();
    assert(result == 0);
}

void combined_proof_harness() {
    proof_harness_newNode();
    proof_harness_main();
}

void proof_harness_newNode() {
    int data;
    __CPROVER_assume(data >= 0);
    __CPROVER_assume(data <= 2147483647);
    struct node *node = newNode(data);
    assert(node->leftNode == NULL);
    assert(node->data == data);
    assert(node->rightNode == NULL);
    free(node);
}

