#include <stdio.h>
struct node {
    int data;
    struct node *leftNode;
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

struct node *newNode(int data){
    struct node *node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->leftNode = NULL;
    node->rightNode = NULL;
    return node;
}

void proof_harness_newNode(){
    int data;
    CPROVER_assume(data >= 0);
    CPROVER_assume(data <= 1000);
    struct node *node = newNode(data);
    assert(node->data == data);
    assert(node->leftNode == NULL);
    assert(node->rightNode == NULL);
}

int main(void){
    proof_harness_newNode();
    return 0;
}