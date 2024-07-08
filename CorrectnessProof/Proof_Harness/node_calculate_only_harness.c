void proof_harness_inorder_display() {
    node *root = NULL;
    int data;
    __CPROVER_assume(data >= 0);
    __CPROVER_assume(data <= 2147483647);
    insert_bt(&root, data);
    inorder_display(root);
    free(root);
}

void proof_harness_delete_bt() {
    node *root = NULL;
    int ele;
    __CPROVER_assume(ele >= 0);
    __CPROVER_assume(ele <= 2147483647);
    insert_bt(&root, ele);
    delete_bt(&root, ele);
    free(root);
}

void proof_harness_postorder_display() {
    node *root = NULL;
    int data;
    __CPROVER_assume(data >= 0);
    __CPROVER_assume(data <= 2147483647);
    insert_bt(&root, data);
    postorder_display(root);
    free(root);
}

void proof_harness_search() {
    node *root = NULL;
    int ele;
    __CPROVER_assume(ele >= 0);
    __CPROVER_assume(ele <= 2147483647);
    insert_bt(&root, ele);
    search(root, ele);
    free(root);
}

void proof_harness_create_node() {
    int data;
    __CPROVER_assume(data >= 0);
    __CPROVER_assume(data <= 2147483647);
    node *ptr = create_node(data);
    assert(ptr->data == data);
    assert(ptr->llink == NULL);
    assert(ptr->rlink == NULL);
    free(ptr);
}

void proof_harness_insert_bt() {
    node *root = NULL;
    int data;
    __CPROVER_assume(data >= 0);
    __CPROVER_assume(data <= 2147483647);
    insert_bt(&root, data);
    if (root != NULL) {
        assert(root->data == data);
    }

void proof_harness_preorder_display() {
    node *root = NULL;
    int data;
    __CPROVER_assume(data >= 0);
    __CPROVER_assume(data <= 2147483647);
    insert_bt(&root, data);
    preorder_display(root);
    free(root);
}

