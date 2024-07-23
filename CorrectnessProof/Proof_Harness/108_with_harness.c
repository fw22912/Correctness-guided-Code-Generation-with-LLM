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

struct TreeNode *convertBST(int *nums, int left, int right)
{
    if (left > right)
        return NULL;
    else
    {
        int mid = (right + left) / 2;
        struct TreeNode *new_val = malloc(sizeof(struct TreeNode));
        new_val->val = nums[mid];
        new_val->left = convertBST(nums, left, mid - 1);
        new_val->right = convertBST(nums, mid + 1, right);
        return new_val;
    }
}

struct TreeNode *sortedArrayToBST(int *nums, int numsSize)
{
    if (numsSize == 0)
        return NULL;
    else
        return convertBST(nums, 0, numsSize - 1);
}


void proof_harness_convertBST() {
    int *nums = (int *)malloc(sizeof(int) * 10);
    __CPROVER_assume(nums != NULL);
    int left;
    int right;
    __CPROVER_assume(left >= 0);
    __CPROVER_assume(right >= 0);
    __CPROVER_assume(left <= right);
    __CPROVER_assume(right < 10);
    struct TreeNode *ret_val = convertBST(nums, left, right);
    free(nums);
}

void proof_harness_sortedArrayToBST() {
    int *nums = (int *)malloc(sizeof(int) * 10);
    __CPROVER_assume(nums != NULL);
    int numsSize;
    __CPROVER_assume(numsSize >= 0);
    __CPROVER_assume(numsSize <= 10);
    struct TreeNode *ret_val = sortedArrayToBST(nums, numsSize);
    free(nums);
}

void combined_proof_harness() {
    proof_harness_convertBST();
    proof_harness_sortedArrayToBST();
}