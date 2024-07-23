void combined_proof_harness(){
    proof_harness_inOrderTraversal();
    proof_harness_preOrderTraversal();
    proof_harness_postOrderTraversal();
    proof_harness_main();
}

void proof_harness_main(){
    
}

void proof_harness_postOrderTraversal(){
    struct node *node = (struct node *)malloc(sizeof(struct node));
    __CPROVER_assume(node != NULL); 
    
    node->leftNode = (struct node *)malloc(sizeof(struct node));
    __CPROVER_assume(node->leftNode != NULL); 
    node->rightNode = (struct node *)malloc(sizeof(struct node));
    __CPROVER_assume(node->rightNode != NULL); 

    node->data = 0;
    node->leftNode->data = 0;
    node->rightNode->data = 0;

    postOrderTraversal(node);
    free(node->leftNode);
    free(node->rightNode);
    free(node);
}

void proof_harness_preOrderTraversal(){
    struct node *node = (struct node *)malloc(sizeof(struct node));
    __CPROVER_assume(node != NULL); 
    
    node->leftNode = (struct node *)malloc(sizeof(struct node));
    __CPROVER_assume(node->leftNode != NULL); 
    node->rightNode = (struct node *)malloc(sizeof(struct node));
    __CPROVER_assume(node->rightNode != NULL); 

    node->data = 0;
    node->leftNode->data = 0;
    node->rightNode->data = 0;

    preOrderTraversal(node);
    free(node->leftNode);
    free(node->rightNode);
    free(node);
}

void proof_harness_inOrderTraversal(){
    struct node *node = (struct node *)malloc(sizeof(struct node));
    __CPROVER_assume(node != NULL); 
    
    node->leftNode = (struct node *)malloc(sizeof(struct node));
    __CPROVER_assume(node->leftNode != NULL); 
    node->rightNode = (struct node *)malloc(sizeof(struct node));
    __CPROVER_assume(node->rightNode != NULL); 

    node->data = 0;
    node->leftNode->data = 0;
    node->rightNode->data = 0;

    inOrderTraversal(node);
    free(node->leftNode);
    free(node->rightNode);
    free(node);
}

