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

struct TreeNode* findKthSmallest(struct TreeNode* node, int* k){
    if (node == NULL){
        return NULL;
    }
    
    struct TreeNode* resultNode = findKthSmallest(node->left, k);
    
    if (resultNode != NULL){
        return resultNode;
    }
    
    *k -= 1;

    if (*k == 0){
        return node;
    }
    
    return findKthSmallest(node->right, k);
}

// Depth-First Search
// Runtime: O(n)
// Space: O(1)
int kthSmallest(struct TreeNode* root, int k){
    return findKthSmallest(root, &k)->val;
}

void proof_harness_findKthSmallest() {
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    __CPROVER_assume(node != NULL);  // Ensure node is not NULL
    int k;
    __CPROVER_assume(k > 0);
    struct TreeNode *resultNode = findKthSmallest(node, &k);
    free(node);
}

void proof_harness_kthSmallest() {
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    __CPROVER_assume(root != NULL);  // Ensure root is not NULL
    int k;
    __CPROVER_assume(k > 0);
    int result = kthSmallest(root, k);
    free(root);
}

void combined_proof_harness() {
    proof_harness_findKthSmallest();
    proof_harness_kthSmallest();
}