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

void transfer(struct node *source, struct node *dest){
    if (source == NULL || dest == NULL) {
        return;
    }
    dest->data += source->data;
    source->data = 0;
}

void proof_harness() {
    struct node *source = newNode(0);
    struct node *dest = newNode(0);
    int data;
    CPROVER_assume(source->data >= 0);
    CPROVER_assume(dest->data >= 0);
    data = source->data;
    transfer(source, dest);
    assert(dest->data == data);
    assert(source->data == 0);
}

int main(void){
    return 0;
}