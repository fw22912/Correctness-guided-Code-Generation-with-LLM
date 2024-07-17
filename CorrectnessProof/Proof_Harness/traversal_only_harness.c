void proof_harness_postOrderTraversal() {
    struct node *node = (struct node *)malloc(sizeof(struct node));
    __CPROVER_assume(node != NULL);
    node->leftNode = NULL;
    node->rightNode = NULL;
    __CPROVER_assume(node->data >= 0 && node->data <= 100);
    postOrderTraversal(node);
    free(node);
}

void proof_harness_preOrderTraversal() {
    struct node *node = (struct node *)malloc(sizeof(struct node));
    __CPROVER_assume(node != NULL);
    node->leftNode = NULL;
    node->rightNode = NULL;
    __CPROVER_assume(node->data >= 0 && node->data <= 100);
    preOrderTraversal(node);
    free(node);
}

void proof_harness_inOrderTraversal() {
    struct node *node = (struct node *)malloc(sizeof(struct node));
    __CPROVER_assume(node != NULL);
    node->leftNode = NULL;
    node->rightNode = NULL;
    __CPROVER_assume(node->data >= 0 && node->data <= 100);
    inOrderTraversal(node);
    free(node);
}

