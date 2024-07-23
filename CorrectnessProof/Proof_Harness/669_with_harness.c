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


// Depth-First Search
// Runtime: O(n)
// Space: O(1)
struct TreeNode* trimBST(struct TreeNode* root, int low, int high){
    if (root == NULL){
        return NULL;
    }
    
    if (root->val > high){
        return trimBST(root->left, low, high);
    }

    if (root->val < low){
        return trimBST(root->right, low, high);
    }
    
    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);
    return root;
}

void proof_harness_trimBST() {
    struct TreeNode *root = NULL;
    int low;
    int high;
    __CPROVER_assume(low <= high);
    struct TreeNode* result = trimBST(root, low, high);
    // TODO: Add assertions to check the correctness of trimBST
}

void proof_harness_main() {
    // TODO: Add assertions to check the correctness of main
}

void combined_proof_harness() {
    proof_harness_trimBST();
    proof_harness_main();
}