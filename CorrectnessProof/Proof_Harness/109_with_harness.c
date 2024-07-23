#include <assert.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *buildBST(struct ListNode *head, struct ListNode *tail)
{
    if (head == tail)
        return NULL;
    struct ListNode *slow = head, *fast = head;
    while (fast != tail && fast->next != tail)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    struct TreeNode *node = malloc(sizeof(struct TreeNode));
    node->val = slow->val;
    node->left = buildBST(head, slow);
    node->right = buildBST(slow->next, tail);
    return node;
}
struct TreeNode *sortedListToBST(struct ListNode *head)
{
    if (!head)
        return NULL;
    else
        return buildBST(head, NULL);
}

void proof_harness_buildBST() {
    struct ListNode *head = NULL;
    struct ListNode *tail = NULL;
    __CPROVER_assume(head != NULL);
    __CPROVER_assume(tail != NULL);
    struct TreeNode *ret_val = buildBST(head, tail);
}

void proof_harness_sortedListToBST() {
    struct ListNode *head = NULL;
    __CPROVER_assume(head != NULL);
    struct TreeNode *ret_val = sortedListToBST(head);
}

void combined_proof_harness() {
    proof_harness_buildBST();
    proof_harness_sortedListToBST();
}