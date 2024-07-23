#include <assert.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *insertIntoBST(struct TreeNode *root, int val)
{
    if (root == NULL)
    {
        struct TreeNode *new_val = malloc(sizeof(struct TreeNode));
        new_val->val = val;
        new_val->left = new_val->right = NULL;
        return new_val;
    }
    else
    {
        if (root->val >= val)
            root->left = insertIntoBST(root->left, val);
        else
            root->right = insertIntoBST(root->right, val);
    }
    return root;
}

void proof_harness_insertIntoBST() {
    struct TreeNode *root = NULL;
    int val;
    __CPROVER_assume(val >= 0);
    __CPROVER_assume(val <= 100);

    root = insertIntoBST(root, val);

    // Assertions to check the properties of the resulting BST
    // Example: Assert that the root node's value is equal to the inserted value
    if (root != NULL) {
        assert(root->val == val);
    }

    // Free the dynamically allocated memory
    // ... (implementation for freeing the tree nodes)
}

void combined_proof_harness() {
    proof_harness_insertIntoBST();
}