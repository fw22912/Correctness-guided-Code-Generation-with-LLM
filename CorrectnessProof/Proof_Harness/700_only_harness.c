void proof_harness_searchBST() {
    struct TreeNode *root = NULL;
    int val;
    __CPROVER_assume(val >= 0);
    __CPROVER_assume(val <= 100);
    struct TreeNode *result = searchBST(root, val);
    if (root == NULL) {
        assert(result == NULL);
    }

void combined_proof_harness() {
    proof_harness_searchBST();
}

