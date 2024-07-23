#include <assert.h>
#include <stdlib.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int maxval(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int maxDepth(struct TreeNode *root)
{
    if (root == NULL)
        return 0;
    else
        return 1 + maxval(maxDepth(root->left), maxDepth(root->right));
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

void combined_proof_harness() {
    proof_harness_maxval();
    proof_harness_maxDepth();
}