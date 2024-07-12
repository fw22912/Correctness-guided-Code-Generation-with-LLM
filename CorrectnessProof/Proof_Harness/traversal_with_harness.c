#include <stdio.h>
    #include <assert.h>

struct node{
    struct node *leftNode;
    int data;
    struct node *rightNode;
};

void inOrderTraversal(struct node *node){
    if (node == NULL) return;
    inOrderTraversal(node->leftNode);
    printf("\t%d\t", node->data);
    inOrderTraversal(node->rightNode);
}

void preOrderTraversal(struct node *node){
    if (node == NULL) return;
    printf("\t%d\t", node->data);
    preOrderTraversal(node->leftNode);
    preOrderTraversal(node->rightNode);
}

void postOrderTraversal(struct node *node){
    if (node == NULL) return;
    postOrderTraversal(node->leftNode);
    postOrderTraversal(node->rightNode);
    printf("\t%d\t", node->data);
}

int main(void){
    return 0;
}

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