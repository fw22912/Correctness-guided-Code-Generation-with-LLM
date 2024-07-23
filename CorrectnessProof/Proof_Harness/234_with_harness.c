#include <assert.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *reverse(struct ListNode *head)
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
bool isPalindrome(struct ListNode *head)
{
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    struct ListNode *last;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (fast != NULL)
        slow = slow->next;
    last = reverse(slow);
    while (last)
    {
        if (head->val != last->val)
            return 0;
        head = head->next;
        last = last->next;
    }
    return 1;
}

void proof_harness_reverse() {
    struct ListNode *head = NULL;
    struct ListNode *node = NULL;
    
    __CPROVER_assume(head == NULL);
    
    int i;
    for (i = 0; i < 10; i++) {
        node = (struct ListNode *) malloc(sizeof(struct ListNode));
        __CPROVER_assume(node != NULL);
        node->val = i;
        node->next = head;
        head = node;
    }
    
    struct ListNode *res = reverse(head);
    
    int count = 0;
    while (res != NULL) {
        count++;
        res = res->next;
    }
    
    assert(count == 10);
    
    res = reverse(head);
    
    while (res != NULL) {
        free(res);
        res = res->next;
    }
}

void proof_harness_isPalindrome() {
    struct ListNode *head = NULL;
    struct ListNode *node = NULL;
    
    __CPROVER_assume(head == NULL);
    
    int i;
    for (i = 0; i < 10; i++) {
        node = (struct ListNode *) malloc(sizeof(struct ListNode));
        __CPROVER_assume(node != NULL);
        node->val = i;
        node->next = head;
        head = node;
    }
    
    bool res = isPalindrome(head);
    
    while (head != NULL) {
        free(head);
        head = head->next;
    }
}

void combined_proof_harness() {
    proof_harness_reverse();
    proof_harness_isPalindrome();
}