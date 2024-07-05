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

void proof_harness_inOrderTraversal(){
    struct node *node = (struct node *)malloc(sizeof(struct node));
    __CPROVER_assume(node != NULL);
    
    node->data = __CPROVER_nondet_int();
    
    struct node *leftNode = (struct node *)malloc(sizeof(struct node));
    __CPROVER_assume(leftNode != NULL);
    node->leftNode = leftNode;
    leftNode->data = __CPROVER_nondet_int();
    
    struct node *rightNode = (struct node *)malloc(sizeof(struct node));
    __CPROVER_assume(rightNode != NULL);
    node->rightNode = rightNode;
    rightNode->data = __CPROVER_nondet_int();
    
    inOrderTraversal(node);
    
    free(node);
    free(leftNode);
    free(rightNode);
}

void proof_harness_preOrderTraversal(){
    struct node *node = (struct node *)malloc(sizeof(struct node));
    __CPROVER_assume(node != NULL);
    
    node->data = __CPROVER_nondet_int();
    
    struct node *leftNode = (struct node *)malloc(sizeof(struct node));
    __CPROVER_assume(leftNode != NULL);
    node->leftNode = leftNode;
    leftNode->data = __CPROVER_nondet_int();
    
    struct node *rightNode = (struct node *)malloc(sizeof(struct node));
    __CPROVER_assume(rightNode != NULL);
    node->rightNode = rightNode;
    rightNode->data = __CPROVER_nondet_int();
    
    preOrderTraversal(node);
    
    free(node);
    free(leftNode);
    free(rightNode);
}

void proof_harness_postOrderTraversal(){
    struct node *node = (struct node *)malloc(sizeof(struct node));
    __CPROVER_assume(node != NULL);
    
    node->data = __CPROVER_nondet_int();
    
    struct node *leftNode = (struct node *)malloc(sizeof(struct node));
    __CPROVER_assume(leftNode != NULL);
    node->leftNode = leftNode;
    leftNode->data = __CPROVER_nondet_int();
    
    struct node *rightNode = (struct node *)malloc(sizeof(struct node));
    __CPROVER_assume(rightNode != NULL);
    node->rightNode = rightNode;
    rightNode->data = __CPROVER_nondet_int();
    
    postOrderTraversal(node);
    
    free(node);
    free(leftNode);
    free(rightNode);
}