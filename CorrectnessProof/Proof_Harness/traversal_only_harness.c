void proof_harness_inOrderTraversal() {
    struct node *node = (struct node *)malloc(sizeof(struct node));
    __CPROVER_assume(node != NULL); 
    node->leftNode = (struct node *)malloc(sizeof(struct node));
    __CPROVER_assume(node->leftNode != NULL); 
    node->rightNode = (struct node *)malloc(sizeof(struct node));
    __CPROVER_assume(node->rightNode != NULL); 
    node->leftNode->leftNode = (struct node *)malloc(sizeof(struct node));
    __CPROVER_assume(node->leftNode->leftNode != NULL); 
    node->leftNode->rightNode = (struct node *)malloc(sizeof(struct node));
    __CPROVER_assume(node->leftNode->rightNode != NULL); 
    node->rightNode->leftNode = (struct node *)malloc(sizeof(struct node));
    __CPROVER_assume(node->rightNode->leftNode != NULL); 
    node->rightNode->rightNode = (struct node *)malloc(sizeof(struct node));
    __CPROVER_assume(node->rightNode->rightNode != NULL); 
    node->leftNode->leftNode->leftNode = NULL;
    node->leftNode->leftNode->rightNode = NULL;
    node->leftNode->rightNode->leftNode = NULL;
    node->leftNode->rightNode->rightNode = NULL;
    node->rightNode->leftNode->leftNode = NULL;
    node->rightNode->leftNode->rightNode = NULL;
    node->rightNode->rightNode->leftNode = NULL;
    node->rightNode->rightNode->rightNode = NULL;
    
    inOrderTraversal(node);
    free(node->rightNode->rightNode);
    free(node->rightNode->leftNode);
    free(node->rightNode);
    free(node->leftNode->rightNode);
    free(node->leftNode->leftNode);
    free(node->leftNode);
    free(node);
}

void proof_harness_postOrderTraversal() {
    struct node *node = (struct node *)malloc(sizeof(struct node));
    __CPROVER_assume(node != NULL); 
    node->leftNode = (struct node *)malloc(sizeof(struct node));
    __CPROVER_assume(node->leftNode != NULL); 
    node->rightNode = (struct node *)malloc(sizeof(struct node));
    __CPROVER_assume(node->rightNode != NULL); 
    node->leftNode->leftNode = (struct node *)malloc(sizeof(struct node));
    __CPROVER_assume(node->leftNode->leftNode != NULL); 
    node->leftNode->rightNode = (struct node *)malloc(sizeof(struct node));
    __CPROVER_assume(node->leftNode->rightNode != NULL); 
    node->rightNode->leftNode = (struct node *)malloc(sizeof(struct node));
    __CPROVER_assume(node->rightNode->leftNode != NULL); 
    node->rightNode->rightNode = (struct node *)malloc(sizeof(struct node));
    __CPROVER_assume(node->rightNode->rightNode != NULL); 
    node->leftNode->leftNode->leftNode = NULL;
    node->leftNode->leftNode->rightNode = NULL;
    node->leftNode->rightNode->leftNode = NULL;
    node->leftNode->rightNode->rightNode = NULL;
    node->rightNode->leftNode->leftNode = NULL;
    node->rightNode->leftNode->rightNode = NULL;
    node->rightNode->rightNode->leftNode = NULL;
    node->rightNode->rightNode->rightNode = NULL;
    
    postOrderTraversal(node);
    free(node->rightNode->rightNode);
    free(node->rightNode->leftNode);
    free(node->rightNode);
    free(node->leftNode->rightNode);
    free(node->leftNode->leftNode);
    free(node->leftNode);
    free(node);
}

void proof_harness_preOrderTraversal() {
    struct node *node = (struct node *)malloc(sizeof(struct node));
    __CPROVER_assume(node != NULL); 
    node->leftNode = (struct node *)malloc(sizeof(struct node));
    __CPROVER_assume(node->leftNode != NULL); 
    node->rightNode = (struct node *)malloc(sizeof(struct node));
    __CPROVER_assume(node->rightNode != NULL); 
    node->leftNode->leftNode = (struct node *)malloc(sizeof(struct node));
    __CPROVER_assume(node->leftNode->leftNode != NULL); 
    node->leftNode->rightNode = (struct node *)malloc(sizeof(struct node));
    __CPROVER_assume(node->leftNode->rightNode != NULL); 
    node->rightNode->leftNode = (struct node *)malloc(sizeof(struct node));
    __CPROVER_assume(node->rightNode->leftNode != NULL); 
    node->rightNode->rightNode = (struct node *)malloc(sizeof(struct node));
    __CPROVER_assume(node->rightNode->rightNode != NULL); 
    node->leftNode->leftNode->leftNode = NULL;
    node->leftNode->leftNode->rightNode = NULL;
    node->leftNode->rightNode->leftNode = NULL;
    node->leftNode->rightNode->rightNode = NULL;
    node->rightNode->leftNode->leftNode = NULL;
    node->rightNode->leftNode->rightNode = NULL;
    node->rightNode->rightNode->leftNode = NULL;
    node->rightNode->rightNode->rightNode = NULL;
    
    preOrderTraversal(node);
    free(node->rightNode->rightNode);
    free(node->rightNode->leftNode);
    free(node->rightNode);
    free(node->leftNode->rightNode);
    free(node->leftNode->leftNode);
    free(node->leftNode);
    free(node);
}

