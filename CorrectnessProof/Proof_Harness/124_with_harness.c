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

#define max(a,b) (((a)>(b))?(a):(b))

int recursiveSolve(struct TreeNode* node, int* result){
    if (node == NULL){
        return 0;
    }

    int leftSum = max(recursiveSolve(node->left, result), 0);
    int rightSum = max(recursiveSolve(node->right, result), 0);

    // Check if it's possible to make a maximum path from left right and current node
    int maxValueNode = node->val + leftSum + rightSum;
    *result = max(maxValueNode, *result);

    // Choose the max sum val path 
    return node->val + max(leftSum, rightSum);
}

// Depth First Search
// Runtime: O(n), n - the number of nodes in tree.
// Space: O(1)
int maxPathSum(struct TreeNode* root){
    const int LOWER_BOUND = -2147483648
    int result = LOWER_BOUND;
    recursiveSolve(root, &result);
    return result;
}

void proof_harness_recursiveSolve(){
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    __CPROVER_assume(node != NULL);  // Ensure node is not NULL
    int result = 0;

    node->val = 0;
    node->left = NULL;
    node->right = NULL;
    int expected = 0;
    int actual = recursiveSolve(node, &result);
    assert(actual == expected);

    free(node);
}

void proof_harness_maxPathSum(){
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    __CPROVER_assume(root != NULL);  // Ensure root is not NULL

    root->val = 0;
    root->left = NULL;
    root->right = NULL;
    int expected = 0;
    int actual = maxPathSum(root);
    assert(actual == expected);

    free(root);
}

void combined_proof_harness(){
    proof_harness_recursiveSolve();
    proof_harness_maxPathSum();
}