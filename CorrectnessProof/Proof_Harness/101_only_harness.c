void proof_harness_checkSymmetric() {
    struct TreeNode *left = NULL;
    struct TreeNode *right = NULL;
    
    __CPROVER_assume(left == NULL || left->val >= 0);
    __CPROVER_assume(left == NULL || left->val <= 2147483647);
    __CPROVER_assume(right == NULL || right->val >= 0);
    __CPROVER_assume(right == NULL || right->val <= 2147483647);
    
    bool result = checkSymmetric(left, right);
    
    if (left == NULL && right == NULL) {
        assert(result == 1);
    }

void combined_proof_harness() {
    proof_harness_checkSymmetric();
    proof_harness_isSymmetric();
}

void proof_harness_isSymmetric() {
    struct TreeNode *root = NULL;
    
    __CPROVER_assume(root == NULL || root->val >= 0);
    __CPROVER_assume(root == NULL || root->val <= 2147483647);
    
    bool result = isSymmetric(root);
    
    if (root == NULL) {
        assert(result == 1);
    }

