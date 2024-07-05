void proof_harness_postOrderTraversal() {
    struct node *node = (struct node *)malloc(sizeof(struct node));
    __CPROVER_assume(node != NULL);
    
    node->data = 0;
    node->leftNode = NULL;
    node->rightNode = NULL;
    postOrderTraversal(node);
    free(node);
}

void proof_harness_inOrderTraversal() {
    struct node *node = (struct node *)malloc(sizeof(struct node));
    __CPROVER_assume(node != NULL);
    
    node->data = 0;
    node->leftNode = NULL;
    node->rightNode = NULL;
    inOrderTraversal(node);
    free(node);
}

void proof_harness_preOrderTraversal() {
    struct node *node = (struct node *)malloc(sizeof(struct node));
    __CPROVER_assume(node != NULL);
    
    node->data = 0;
    node->leftNode = NULL;
    node->rightNode = NULL;
    preOrderTraversal(node);
    free(node);
}

