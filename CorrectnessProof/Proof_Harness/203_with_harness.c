#include <assert.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *removeElements(struct ListNode *head, int val)
{
    if (head == NULL)
        return NULL;
    if (head->val == val)
    {
        return removeElements(head->next, val);
    }
    else
    {
        head->next = removeElements(head->next, val);
    }
    return head;
}

void proof_harness_removeElements() {
    struct ListNode *head = NULL;
    int val;
    __CPROVER_assume(val >= 0);
    __CPROVER_assume(val <= 2147483647);

    struct ListNode *result = removeElements(head, val);
    
    // Check if the list is empty or not.
    if (head == NULL) {
        assert(result == NULL);
    } else {
        struct ListNode *current = head;
        while (current != NULL) {
            assert(current->val != val);
            current = current->next;
        }
    }
}

void combined_proof_harness() {
    proof_harness_removeElements();
}