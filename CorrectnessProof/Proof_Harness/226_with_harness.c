#include <assert.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *invertTree(struct TreeNode *root)
{
    struct TreeNode *tmp;
    if (root == NULL)
        return NULL;
    tmp = root->left;
    root->left = root->right;
    root->right = tmp;

    invertTree(root->left);
    invertTree(root->right);
    return root;
}

void proof_harness_invertTree() {
    struct TreeNode *root = NULL;
    __CPROVER_assume(root == NULL || (root->left == NULL || (root->left->left == NULL && root->left->right == NULL)) && (root->right == NULL || (root->right->left == NULL && root->right->right == NULL)));
    struct TreeNode *ret_value = invertTree(root);
    __CPROVER_assume(ret_value == NULL || (ret_value->left == NULL || (ret_value->left->left == NULL && ret_value->left->right == NULL)) && (ret_value->right == NULL || (ret_value->right->left == NULL && ret_value->right->right == NULL)));
}

void proof_harness_main() {
    struct TreeNode *root = NULL;
    __CPROVER_assume(root == NULL || (root->left == NULL || (root->left->left == NULL && root->left->right == NULL)) && (root->right == NULL || (root->right->left == NULL && root->right->right == NULL)));
    struct TreeNode *ret_value = invertTree(root);
    __CPROVER_assume(ret_value == NULL || (ret_value->left == NULL || (ret_value->left->left == NULL && ret_value->left->right == NULL)) && (ret_value->right == NULL || (ret_value->right->left == NULL && ret_value->right->right == NULL)));
}

void combined_proof_harness() {
    proof_harness_invertTree();
    proof_harness_main();
}