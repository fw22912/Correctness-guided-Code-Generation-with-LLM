void combined_proof_harness(){
    proof_harness_recursiveSolve();
    proof_harness_maxAncestorDiff();
}

void proof_harness_recursiveSolve(){
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    __CPROVER_assume(node != NULL);
    int result = 0;
    int minVal = 0;
    int maxVal = 0;
    __CPROVER_assume(node->val >= 0);
    __CPROVER_assume(minVal >= 0);
    __CPROVER_assume(maxVal >= 0);
    recursiveSolve(node, &result, minVal, maxVal);
    free(node);
}

void proof_harness_maxAncestorDiff(){
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    __CPROVER_assume(root != NULL);
    __CPROVER_assume(root->val >= 0);
    int result = maxAncestorDiff(root);
    free(root);
}

