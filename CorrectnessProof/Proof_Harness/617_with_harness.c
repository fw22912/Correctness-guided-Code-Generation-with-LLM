#include <assert.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *newNode(int item)
{
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = item;
    node->left = node->right = NULL;
    return node;
}

struct TreeNode *mergeTrees(struct TreeNode *t1, struct TreeNode *t2)
{
    if (t1 == NULL && t2 == NULL)
        return NULL;
    int item = (t1 == NULL ? 0 : t1->val) + (t2 == NULL ? 0 : t2->val);
    struct TreeNode *node = newNode(item);
    node->left =
        mergeTrees(t1 == NULL ? NULL : t1->left, t2 == NULL ? NULL : t2->left);
    node->right = mergeTrees(t1 == NULL ? NULL : t1->right,
                             t2 == NULL ? NULL : t2->right);
    return node;
}

void proof_harness_newNode() {
    int item;
    __CPROVER_assume(item >= 0);
    __CPROVER_assume(item <= 2147483647);

    struct TreeNode *ret_val = newNode(item);
    assert(ret_val != NULL);
    assert(ret_val->val == item);
    assert(ret_val->left == NULL);
    assert(ret_val->right == NULL);
}

void proof_harness_mergeTrees() {
    struct TreeNode *t1;
    struct TreeNode *t2;

    __CPROVER_assume(t1 == NULL || t1 != NULL);
    __CPROVER_assume(t2 == NULL || t2 != NULL);

    struct TreeNode *ret_val = mergeTrees(t1, t2);
    // TODO: Add assertions for mergeTrees()
}

void combined_proof_harness() {
    proof_harness_newNode();
    proof_harness_mergeTrees();
}