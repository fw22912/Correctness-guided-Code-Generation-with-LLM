#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *leftNode;
    int data;
    struct node *rightNode;
};

struct node *newNode(int data){
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->leftNode = NULL;
    node->data = data; node->rightNode = NULL;
    return node;
}

void transfer(struct node **root, int data1, int data2){
    if (*root == NULL){
        *root = newNode(data1);
        return;
    }
    if ((*root)->data == data1){
        (*root)->data = data2;
        return;
    }
    if (data1 < (*root)->data){
        transfer(&(*root)->leftNode, data1, data2);
    } else {
        transfer(&(*root)->rightNode, data1, data2);
    }
}

void proof_harness() {
    struct node *root = NULL;
    int data1, data2;
    transfer(&root, data1, data2);
    CPROVER_assert(root != NULL, "Root should not be null");
}

int main(void){
    return 0;
}