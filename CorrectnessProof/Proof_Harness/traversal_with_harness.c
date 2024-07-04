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

void proof_harness(){
    struct node *node;
    CPROVER_assume(node != NULL);
    inOrderTraversal(node);
    preOrderTraversal(node);
    postOrderTraversal(node);
}

int main(void){
    return 0;
}