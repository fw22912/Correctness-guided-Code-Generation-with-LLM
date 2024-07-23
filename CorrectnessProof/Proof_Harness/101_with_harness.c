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

bool checkSymmetric(struct TreeNode *left, struct TreeNode *right)
{
    if (!left || !right)
        return left == right;
    if (left->val != right->val)
        return 0;
    return checkSymmetric(left->left, right->right) &&
           checkSymmetric(left->right, right->left);
}

bool isSymmetric(struct TreeNode *root)
{
    return root == NULL || checkSymmetric(root->left, root->right);
}

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
    } else if (left != NULL && right != NULL && left->val == right->val) {
        assert(result == checkSymmetric(left->left, right->right) && checkSymmetric(left->right, right->left));
    } else {
        assert(result == 0);
    }
}

void proof_harness_isSymmetric() {
    struct TreeNode *root = NULL;
    
    __CPROVER_assume(root == NULL || root->val >= 0);
    __CPROVER_assume(root == NULL || root->val <= 2147483647);
    
    bool result = isSymmetric(root);
    
    if (root == NULL) {
        assert(result == 1);
    } else {
        assert(result == checkSymmetric(root->left, root->right));
    }
}

void combined_proof_harness() {
    proof_harness_checkSymmetric();
    proof_harness_isSymmetric();
}