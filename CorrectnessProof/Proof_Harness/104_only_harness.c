void combined_proof_harness() {
    proof_harness_maxval();
    proof_harness_maxDepth();
}

void proof_harness_maxval() {
    int a;
    int b;
    __CPROVER_assume(a >= 0);
    __CPROVER_assume(b >= 0);
    int expected_result = (a > b) ? a : b;
    int result = maxval(a, b);
    assert(result == expected_result);
}

void proof_harness_maxDepth() {
    struct TreeNode *root = NULL;
    int expected_result = 0;
    int result = maxDepth(root);
    assert(result == expected_result);
}

