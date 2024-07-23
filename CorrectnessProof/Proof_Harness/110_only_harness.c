void combined_proof_harness() {
    proof_harness_max();
    proof_harness_height();
    proof_harness_isBalanced();
}

void proof_harness_max() {
    int a;
    int b;
    __CPROVER_assume(a >= INT_MIN && a <= INT_MAX);
    __CPROVER_assume(b >= INT_MIN && b <= INT_MAX);
    int result = max(a, b);
    assert(result == (a >= b ? a : b));
}

void proof_harness_height() {
    struct TreeNode *root = NULL;
    __CPROVER_assume(root == NULL || root != NULL);
    if (root != NULL) {
        __CPROVER_assume(root->val >= INT_MIN && root->val <= INT_MAX);
        __CPROVER_assume(root->left == NULL || root->left != NULL);
        if (root->left != NULL) {
            __CPROVER_assume(root->left->val >= INT_MIN && root->left->val <= INT_MAX);
            __CPROVER_assume(root->left->left == NULL || root->left->left != NULL);
            __CPROVER_assume(root->left->right == NULL || root->left->right != NULL);
        }

void proof_harness_isBalanced() {
    struct TreeNode *root = NULL;
    __CPROVER_assume(root == NULL || root != NULL);
    if (root != NULL) {
        __CPROVER_assume(root->val >= INT_MIN && root->val <= INT_MAX);
        __CPROVER_assume(root->left == NULL || root->left != NULL);
        if (root->left != NULL) {
            __CPROVER_assume(root->left->val >= INT_MIN && root->left->val <= INT_MAX);
            __CPROVER_assume(root->left->left == NULL || root->left->left != NULL);
            __CPROVER_assume(root->left->right == NULL || root->left->right != NULL);
        }

