void combined_proof_harness() {
    proof_harness_newNode();
    proof_harness_mergeTrees();
}

void proof_harness_newNode() {
    int item;
    __CPROVER_assume(item >= 0);
    __CPROVER_assume(item <= 2147483647);

    struct TreeNode *ret_val = newNode(item);
    assert(ret_val != NULL);
    assert(ret_val->val == item);
    assert(ret_val->left == NULL);
    assert(ret_val->right == NULL);
}

void proof_harness_mergeTrees() {
    struct TreeNode *t1;
    struct TreeNode *t2;

    __CPROVER_assume(t1 == NULL || t1 != NULL);
    __CPROVER_assume(t2 == NULL || t2 != NULL);

    struct TreeNode *ret_val = mergeTrees(t1, t2);
    // TODO: Add assertions for mergeTrees()
}

