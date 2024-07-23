#include <assert.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isleaf(struct TreeNode *root)
{
    return root->left == NULL && root->right == NULL;
}

int sumOfLeftLeaves(struct TreeNode *root)
{
    if (root == NULL)
        return 0;
    if (root->left)
    {
        if (isleaf(root->left))
            return root->left->val + sumOfLeftLeaves(root->right);
    }
    return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
}

void proof_harness_isleaf() {
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    __CPROVER_assume(root != NULL);
    struct TreeNode *left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    __CPROVER_assume(left != NULL);
    struct TreeNode *right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    __CPROVER_assume(right != NULL);
    root->left = left;
    root->right = right;
    
    bool expected_result;
    if (left == NULL && right == NULL) {
        expected_result = true;
    } else {
        expected_result = false;
    }
    
    bool actual_result = isleaf(root);
    assert(actual_result == expected_result);
    
    free(root);
    free(left);
    free(right);
}

void proof_harness_sumOfLeftLeaves() {
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    __CPROVER_assume(root != NULL);
    struct TreeNode *left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    __CPROVER_assume(left != NULL);
    struct TreeNode *right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    __CPROVER_assume(right != NULL);
    root->left = left;
    root->right = right;
    
    int expected_result;
    if (root == NULL) {
        expected_result = 0;
    } else if (left && isleaf(left)) {
        expected_result = left->val + sumOfLeftLeaves(right);
    } else {
        expected_result = sumOfLeftLeaves(left) + sumOfLeftLeaves(right);
    }
    
    int actual_result = sumOfLeftLeaves(root);
    assert(actual_result == expected_result);
    
    free(root);
    free(left);
    free(right);
}

void combined_proof_harness() {
    proof_harness_isleaf();
    proof_harness_sumOfLeftLeaves();
}