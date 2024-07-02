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

int main(void){
    return 0;
}
