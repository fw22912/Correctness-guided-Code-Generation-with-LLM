#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

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

int main(void){
    return 0;
}

void proof_harness_newNode() {
    int data;
    __CPROVER_assume(data >= 0);
    __CPROVER_assume(data <= 2147483647);
    struct node *node = newNode(data);
    assert(node->data == data);
    assert(node->leftNode == NULL);
    assert(node->rightNode == NULL);
    free(node);
}