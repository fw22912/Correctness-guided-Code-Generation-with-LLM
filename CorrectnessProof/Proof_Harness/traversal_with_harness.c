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

void proof_harness_postOrderTraversal() {
    struct node *node = (struct node *)malloc(sizeof(struct node));
    __CPROVER_assume(node != NULL);
    
    node->data = 0;
    node->leftNode = NULL;
    node->rightNode = NULL;
    postOrderTraversal(node);
    free(node);
}