void proof_harness_newNode(){
        int data;
        __CPROVER_assume(data >= 0);
        __CPROVER_assume(data <= 2147483647);
        struct node *node = newNode(data);
        assert(node->leftNode == NULL);
        assert(node->data == data);
        assert(node->rightNode == NULL);
        free(node);
    }

