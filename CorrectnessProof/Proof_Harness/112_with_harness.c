#include <assert.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool hasPathSum(struct TreeNode *root, int sum)
{
    if (root == NULL)
        return 0;
    if (!root->left && !root->right && sum - root->val == 0)
        return 1;
    return hasPathSum(root->left, sum - root->val) ||
           hasPathSum(root->right, sum - root->val);
}

void proof_harness_hasPathSum() {
    struct TreeNode *root = NULL;
    int sum;
    __CPROVER_assume(sum >= 0);

    bool result = hasPathSum(root, sum);
    __CPROVER_assert(result == 0, "hasPathSum should return false for a NULL root");

    root = malloc(sizeof(struct TreeNode));
    __CPROVER_assume(root != NULL);
    root->val = 1;
    root->left = NULL;
    root->right = NULL;

    sum = 1;
    result = hasPathSum(root, sum);
    __CPROVER_assert(result == 1, "hasPathSum should return true for a single node with matching sum");

    sum = 2;
    result = hasPathSum(root, sum);
    __CPROVER_assert(result == 0, "hasPathSum should return false for a single node with mismatching sum");

    root->left = malloc(sizeof(struct TreeNode));
    __CPROVER_assume(root->left != NULL);
    root->left->val = 2;
    root->left->left = NULL;
    root->left->right = NULL;

    sum = 3;
    result = hasPathSum(root, sum);
    __CPROVER_assert(result == 1, "hasPathSum should return true for a path sum matching the sum");

    sum = 4;
    result = hasPathSum(root, sum);
    __CPROVER_assert(result == 0, "hasPathSum should return false for a path sum not matching the sum");

    free(root->left);
    free(root);
}

void combined_proof_harness() {
    proof_harness_hasPathSum();
}