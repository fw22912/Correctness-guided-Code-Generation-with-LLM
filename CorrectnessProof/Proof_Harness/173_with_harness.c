#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct
{
    int *values;
    int CurrentIndex;
    int NumberOfNodes;
} BSTIterator;

void TraverseAndAssign(struct TreeNode *root, BSTIterator *obj)
{
    if (!root)
        return;
    if (root->left)
        TraverseAndAssign(root->left, obj);
    obj->values[obj->CurrentIndex] = root->val;
    obj->CurrentIndex++;
    if (root->right)
        TraverseAndAssign(root->right, obj);
}

int TotalNodes(struct TreeNode *root)
{
    if (!root)
        return 0;
    int nodes_left = TotalNodes(root->left);
    int nodes_right = TotalNodes(root->right);
    return nodes_left + nodes_right + 1;
}

BSTIterator *bSTIteratorCreate(struct TreeNode *root)
{
    int n = TotalNodes(root);
    int size = n + 1;
    printf("%d", size);
    BSTIterator *obj = (BSTIterator *)malloc(sizeof(BSTIterator));
    obj->values = (int *)calloc(size, sizeof(int));
    obj->CurrentIndex = 0;
    obj->NumberOfNodes = n;
    obj->values[size - 1] = INT_MAX;
    TraverseAndAssign(root, obj);
    obj->CurrentIndex = 0;
    return obj;
}

/** @return the next smallest number */
int bSTIteratorNext(BSTIterator *obj)
{
    int NextValue = obj->values[obj->CurrentIndex];
    obj->CurrentIndex++;
    return NextValue;
}

/** @return whether we have a next smallest number */
bool bSTIteratorHasNext(BSTIterator *obj)
{
    if (!obj->NumberOfNodes)
    {
        return false;
    }
    printf(" Here ");
    return (obj->values[obj->CurrentIndex] == INT_MAX) ? false : true;
}

void bSTIteratorFree(BSTIterator *obj)
{
    free(obj->values);
    free(obj);
}

void proof_harness_bSTIteratorCreate() {
    struct TreeNode *root = NULL; // Create a NULL root for testing
    BSTIterator *obj = bSTIteratorCreate(root);
    assert(obj != NULL); 
    assert(obj->values != NULL); 
    assert(obj->NumberOfNodes == 0);
    assert(obj->CurrentIndex == 0);
    assert(obj->values[0] == INT_MAX); 
    bSTIteratorFree(obj); 
}

void proof_harness_bSTIteratorNext() {
    struct TreeNode *root = NULL; // Create a NULL root for testing
    BSTIterator *obj = bSTIteratorCreate(root);
    int NextValue = bSTIteratorNext(obj);
    assert(NextValue == INT_MAX); 
    bSTIteratorFree(obj);
}

void proof_harness_bSTIteratorHasNext() {
    struct TreeNode *root = NULL; // Create a NULL root for testing
    BSTIterator *obj = bSTIteratorCreate(root);
    bool hasNext = bSTIteratorHasNext(obj);
    assert(hasNext == false); 
    bSTIteratorFree(obj); 
}

void proof_harness_bSTIteratorFree() {
    struct TreeNode *root = NULL; // Create a NULL root for testing
    BSTIterator *obj = bSTIteratorCreate(root);
    bSTIteratorFree(obj);
    // After freeing, we can't access obj anymore. So, we can't use assert here
}

void combined_proof_harness() {
    proof_harness_bSTIteratorCreate();
    proof_harness_bSTIteratorNext();
    proof_harness_bSTIteratorHasNext();
    proof_harness_bSTIteratorFree();
}

int main() {
    combined_proof_harness();
    return 0;
}