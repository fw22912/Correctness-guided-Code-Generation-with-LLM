#include <assert.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int max(int a, int b) { return a >= b ? a : b; }

int height(struct TreeNode *root)
{
    if (root == NULL)
        return 0;
    else
        return 1 + max(height(root->left), height(root->right));
}

bool isBalanced(struct TreeNode *root)
{
    if (root == NULL)
        return 1;
    int left = height(root->left);
    int right = height(root->right);
    return abs(left - right) <= 1 && isBalanced(root->left) &&
           isBalanced(root->right);
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
        __CPROVER_assume(root->right == NULL || root->right != NULL);
        if (root->right != NULL) {
            __CPROVER_assume(root->right->val >= INT_MIN && root->right->val <= INT_MAX);
            __CPROVER_assume(root->right->left == NULL || root->right->left != NULL);
            __CPROVER_assume(root->right->right == NULL || root->right->right != NULL);
        }
    }
    int result = height(root);
    if (root == NULL) {
        assert(result == 0);
    } else {
        assert(result == 1 + max(height(root->left), height(root->right)));
    }
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
        __CPROVER_assume(root->right == NULL || root->right != NULL);
        if (root->right != NULL) {
            __CPROVER_assume(root->right->val >= INT_MIN && root->right->val <= INT_MAX);
            __CPROVER_assume(root->right->left == NULL || root->right->left != NULL);
            __CPROVER_assume(root->right->right == NULL || root->right->right != NULL);
        }
    }
    bool result = isBalanced(root);
    if (root == NULL) {
        assert(result == 1);
    } else {
        int left = height(root->left);
        int right = height(root->right);
        assert(result == (abs(left - right) <= 1 && isBalanced(root->left) && isBalanced(root->right)));
    }
}

void combined_proof_harness() {
    proof_harness_max();
    proof_harness_height();
    proof_harness_isBalanced();
}