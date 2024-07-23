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
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *searchBST(struct TreeNode *root, int val)
{
    if (!root)
        return NULL;

    if (root->val == val)
    {
        return root;
    }
    else if (root->val > val)
    {
        return searchBST(root->left, val);
    }
    else
    {
        return searchBST(root->right, val);
    }
}

void proof_harness_searchBST() {
    struct TreeNode *root = NULL;
    int val;
    __CPROVER_assume(val >= 0);
    __CPROVER_assume(val <= 100);
    struct TreeNode *result = searchBST(root, val);
    if (root == NULL) {
        assert(result == NULL);
    }
}

void combined_proof_harness() {
    proof_harness_searchBST();
}