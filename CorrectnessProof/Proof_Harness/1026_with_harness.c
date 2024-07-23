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
#define min(a,b) (((a)<(b))?(a):(b))

void recursiveSolve(struct TreeNode* node, int* result, int minVal, int maxVal){
    if (node == NULL){
        return;
    }

    *result = max(*result, abs(minVal - node->val));
    *result = max(*result, abs(maxVal - node->val));

    minVal = min(minVal, node->val);
    maxVal = max(maxVal, node->val);

    recursiveSolve(node->left, result, minVal, maxVal);
    recursiveSolve(node->right, result, minVal, maxVal);
}

// Depth First Search
// If The maximum diff is exists it should be the difference of the MAX or MIN value in the tree path to the LEAF
// Runtime: O(n)
// Space: O(1)
int maxAncestorDiff(struct TreeNode* root){
    int result = 0;
    int maxVal = root->val;
    int minVal = root->val;
    recursiveSolve(root, &result, minVal, maxVal);
    return result;
}

void proof_harness_recursiveSolve(){
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    __CPROVER_assume(node != NULL);
    int result = 0;
    int minVal = 0;
    int maxVal = 0;
    __CPROVER_assume(node->val >= 0);
    __CPROVER_assume(minVal >= 0);
    __CPROVER_assume(maxVal >= 0);
    recursiveSolve(node, &result, minVal, maxVal);
    free(node);
}

void proof_harness_maxAncestorDiff(){
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    __CPROVER_assume(root != NULL);
    __CPROVER_assume(root->val >= 0);
    int result = maxAncestorDiff(root);
    free(root);
}

void combined_proof_harness(){
    proof_harness_recursiveSolve();
    proof_harness_maxAncestorDiff();
}