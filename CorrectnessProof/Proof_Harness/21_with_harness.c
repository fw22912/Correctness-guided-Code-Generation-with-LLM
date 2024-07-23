#include <assert.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

/*
 * Iterative approach
 */
struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *list = NULL;
    struct ListNode *tmp = NULL;

    if (!l1)
        return l2;
    if (!l2)
        return l1;

    if (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            list = tmp = l1;
            l1 = l1->next;
        }
        else
        {
            list = tmp = l2;
            l2 = l2->next;
        }

        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                tmp->next = l1;
                l1 = l1->next;
            }
            else
            {
                tmp->next = l2;
                l2 = l2->next;
            }
            tmp = tmp->next;
        }

        if (l1)
            tmp->next = l1;
        if (l2)
            tmp->next = l2;

        return list;
    }

    return NULL;
}

/*
 * Recursive approach
 */
struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
    if (!l1)
        return l2;
    if (!l2)
        return l1;
    if (l1->val < l2->val)
    {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

void proof_harness_mergeTwoLists() {
    struct ListNode *l1 = NULL;
    struct ListNode *l2 = NULL;
    __CPROVER_assume(l1 == NULL || l1 != NULL);
    __CPROVER_assume(l2 == NULL || l2 != NULL);
    struct ListNode *ret = mergeTwoLists(l1, l2);
    __CPROVER_assume(ret == NULL || ret != NULL);
}

void combined_proof_harness() {
    proof_harness_mergeTwoLists();
}