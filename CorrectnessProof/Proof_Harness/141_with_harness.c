#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head)
{
    struct ListNode *fast = head, *slow = head;
    while (slow && fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            return true;
    }
    return false;
}

struct ListNode {
    int val;
    struct ListNode *next;
};

void proof_harness_hasCycle() {
    struct ListNode *head = NULL;
    struct ListNode *current = NULL;
    struct ListNode *cycle_start = NULL;
    bool has_cycle = __CPROVER_choice_bool();
    
    if (has_cycle) {
        cycle_start = (struct ListNode *)malloc(sizeof(struct ListNode));
        __CPROVER_assume(cycle_start != NULL);
        cycle_start->val = __CPROVER_nondet_int();
        cycle_start->next = NULL;
    
        head = cycle_start;
        current = cycle_start;
    
        int num_nodes = __CPROVER_nondet_int();
        for (int i = 0; i < num_nodes; i++) {
            struct ListNode *new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
            __CPROVER_assume(new_node != NULL);
            new_node->val = __CPROVER_nondet_int();
            new_node->next = NULL;
            current->next = new_node;
            current = new_node;
        }
        current->next = cycle_start;
    } else {
        int num_nodes = __CPROVER_nondet_int();
        for (int i = 0; i < num_nodes; i++) {
            struct ListNode *new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
            __CPROVER_assume(new_node != NULL);
            new_node->val = __CPROVER_nondet_int();
            new_node->next = NULL;
            if (head == NULL) {
                head = new_node;
                current = new_node;
            } else {
                current->next = new_node;
                current = new_node;
            }
        }
    }
    
    bool result = hasCycle(head);
    assert(result == has_cycle);
    
    // Free the linked list
    current = head;
    while (current != NULL) {
        struct ListNode *temp = current->next;
        free(current);
        current = temp;
    }
}

void combined_proof_harness() {
    proof_harness_hasCycle();
}