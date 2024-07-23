#include <assert.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *swapPairs(struct ListNode *head)
{
    if (!head || !head->next)
        return head;
    struct ListNode *tmp = head->next;
    head->next = swapPairs(head->next->next);
    tmp->next = head;
    return tmp;
}

void proof_harness_swapPairs() {
    struct ListNode *head = NULL;
    struct ListNode *current = NULL;
    struct ListNode *tmp = NULL;
    int i;

    for (i = 0; i < 10; i++) {
        tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
        __CPROVER_assume(tmp != NULL);
        tmp->val = i;
        tmp->next = NULL;
        if (head == NULL) {
            head = tmp;
            current = tmp;
        } else {
            current->next = tmp;
            current = tmp;
        }
    }
    struct ListNode *result = swapPairs(head);
    // Check that the result is valid
    struct ListNode *p = result;
    i = 0;
    while (p != NULL) {
        if (i % 2 == 0) {
            assert(p->val == i + 1);
        } else {
            assert(p->val == i - 1);
        }
        p = p->next;
        i++;
    }

    // Free the list
    p = result;
    while (p != NULL) {
        tmp = p->next;
        free(p);
        p = tmp;
    }
}

void combined_proof_harness() {
    proof_harness_swapPairs();
}