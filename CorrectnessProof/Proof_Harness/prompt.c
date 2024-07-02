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

void transfer(struct node *source, struct node *dest, int amount) {
    if (source == NULL || dest == NULL) {
        return;
    }
    source->data -= amount;
    dest->data += amount;
}

void proof_harness() {
    struct node *source;
    struct node *dest;
    int amount;
    CPROVER_assume(source != NULL);
    CPROVER_assume(dest != NULL);
    CPROVER_assume(source->data >= 0);
    CPROVER_assume(dest->data >= 0);
    CPROVER_assume(amount > 0);
    CPROVER_assume(source->data >= amount);

    int initial_source_data = source->data;
    int initial_dest_data = dest->data;
    transfer(source, dest, amount);
    assert(source->data == initial_source_data - amount);
    assert(dest->data == initial_dest_data + amount);
}

int main(void){
    return 0;
}