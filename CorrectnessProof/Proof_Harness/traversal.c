#include <stdio.h>

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