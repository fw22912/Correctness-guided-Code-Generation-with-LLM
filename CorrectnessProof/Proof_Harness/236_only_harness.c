void proof_harness_freeList(){
    struct ListItem *target = malloc(sizeof(struct ListItem));
    __CPROVER_assume(target != NULL);
    freeList(target);
}

void proof_harness_lowestCommonAncestor(){
    struct TreeNode *root = malloc(sizeof(struct TreeNode));
    __CPROVER_assume(root != NULL);
    struct TreeNode *p = malloc(sizeof(struct TreeNode));
    __CPROVER_assume(p != NULL);
    struct TreeNode *q = malloc(sizeof(struct TreeNode));
    __CPROVER_assume(q != NULL);
    struct TreeNode *result = lowestCommonAncestor(root, p, q);
    free(root);
    free(p);
    free(q);
}

void combined_proof_harness(){
    proof_harness_findTargetPath();
    proof_harness_freeList();
    proof_harness_lowestCommonAncestor();
}

void proof_harness_findTargetPath(){
    struct TreeNode *node = malloc(sizeof(struct TreeNode));
    __CPROVER_assume(node != NULL);
    struct TreeNode *target = malloc(sizeof(struct TreeNode));
    __CPROVER_assume(target != NULL);
    struct ListItem *path = malloc(sizeof(struct ListItem));
    __CPROVER_assume(path != NULL);
    bool result = findTargetPath(node, target, path);
    free(node);
    free(target);
    free(path);
}

