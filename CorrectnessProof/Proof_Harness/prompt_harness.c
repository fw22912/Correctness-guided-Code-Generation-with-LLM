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

void proof_harness_newNode(){
    int data;
    struct node *node;
    node = newNode(data);
    assert(node->data == data);
    assert(node->leftNode == NULL);
    assert(node->rightNode == NULL);
}

int main(void){
    proof_harness_newNode();
    return 0;
}