#include <assert.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *detectCycle(struct ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    struct ListNode *slow, *fast;
    slow = fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            struct ListNode *entry = head;
            while (slow != entry)
            {
                slow = slow->next;
                entry = entry->next;
            }
            return entry;
        }
    }
    return NULL;
}

void proof_harness_detectCycle() {
    struct ListNode *head = NULL;
    struct ListNode *slow, *fast;
    struct ListNode *entry;
    
    __CPROVER_assume(head == NULL || head->next == NULL); 
    slow = fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            entry = head;
            while (slow != entry)
            {
                slow = slow->next;
                entry = entry->next;
            }
            assert(detectCycle(head) == entry);
        }
    }
    assert(detectCycle(head) == NULL);
}

void combined_proof_harness() {
    proof_harness_detectCycle();
}

int main() {
    combined_proof_harness();
    return 0;
}