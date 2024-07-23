void combined_proof_harness(){
    proof_harness_recursiveSolve();
    proof_harness_maxPathSum();
}

void proof_harness_maxPathSum(){
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    __CPROVER_assume(root != NULL);  // Ensure root is not NULL

    root->val = 0;
    root->left = NULL;
    root->right = NULL;
    int expected = 0;
    int actual = maxPathSum(root);
    assert(actual == expected);

    free(root);
}

void proof_harness_recursiveSolve(){
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    __CPROVER_assume(node != NULL);  // Ensure node is not NULL
    int result = 0;

    node->val = 0;
    node->left = NULL;
    node->right = NULL;
    int expected = 0;
    int actual = recursiveSolve(node, &result);
    assert(actual == expected);

    free(node);
}

