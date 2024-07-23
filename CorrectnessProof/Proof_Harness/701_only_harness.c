void proof_harness_insertIntoBST() {
    struct TreeNode *root = NULL;
    int val;
    __CPROVER_assume(val >= 0);
    __CPROVER_assume(val <= 100);

    root = insertIntoBST(root, val);

    // Assertions to check the properties of the resulting BST
    // Example: Assert that the root node's value is equal to the inserted value
    if (root != NULL) {
        assert(root->val == val);
    }

void combined_proof_harness() {
    proof_harness_insertIntoBST();
}

