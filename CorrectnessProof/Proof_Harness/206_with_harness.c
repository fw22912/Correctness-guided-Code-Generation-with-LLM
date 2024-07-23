#include <assert.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *reverseList(struct ListNode *head)
{
    struct ListNode *res = NULL;
    while (head)
    {
        struct ListNode *pre_node = head;
        head = head->next;
        pre_node->next = res;
        res = pre_node;
    }
    return res;
}

void proof_harness_reverseList() {
    struct ListNode *head = NULL;
    struct ListNode *current = NULL;
    int i;

    for (i = 0; i < 10; i++) {
        struct ListNode *new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
        __CPROVER_assume(new_node != NULL);
        new_node->val = i;
        new_node->next = NULL;
        if (head == NULL) {
            head = new_node;
            current = new_node;
        } else {
            current->next = new_node;
            current = new_node;
        }
    }

    struct ListNode *reversed_head = reverseList(head);

    // Check if the list is reversed correctly
    struct ListNode *p = reversed_head;
    i = 9;
    while (p != NULL) {
        assert(p->val == i);
        p = p->next;
        i--;
    }
    // Free the linked list
    p = head;
    while (p != NULL) {
        struct ListNode *temp = p;
        p = p->next;
        free(temp);
    }
}

int main() {
    proof_harness_reverseList();
    return 0;
}

void combined_proof_harness() {
    proof_harness_reverseList();
}