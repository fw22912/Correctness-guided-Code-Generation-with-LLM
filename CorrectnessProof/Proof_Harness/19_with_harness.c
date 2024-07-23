#include <assert.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *removeNthFromEnd(struct ListNode *head, int n) {
    struct ListNode entry, *p_free, *p = head;
    int i, sz = 0;
    entry.next = head;
    while (p != NULL) {
        p = p->next;
        sz++;
    }
    for (i = 0, p = &entry; i < sz - n; i++, p = p -> next)
    ;
    p_free = p->next;
    if (n != 1) {
        p->next = p->next->next;
    } else {
        p->next = NULL;
    }
    free(p_free);
    return entry.next;
}

struct ListNode* create_list_node(int val) {
    struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
    if (node == NULL) {
        return NULL;
    }
    node->val = val;
    node->next = NULL;
    return node;
}

struct ListNode* create_linked_list(int *vals, int size) {
    if (size == 0) {
        return NULL;
    }
    struct ListNode *head = create_list_node(vals[0]);
    struct ListNode *current = head;
    for (int i = 1; i < size; i++) {
        current->next = create_list_node(vals[i]);
        current = current->next;
    }
    return head;
}

void free_linked_list(struct ListNode *head) {
    struct ListNode *current = head;
    while (current != NULL) {
        struct ListNode *next = current->next;
        free(current);
        current = next;
    }
}

void proof_harness_removeNthFromEnd() {
    int vals[] = {1, 2, 3, 4, 5};
    int size = sizeof(vals) / sizeof(vals[0]);
    int n;

    __CPROVER_assume(n >= 1 && n <= size);

    struct ListNode *head = create_linked_list(vals, size);
    struct ListNode *expected_head = create_linked_list(vals, size);
    struct ListNode *expected_current = expected_head;
    for (int i = 0; i < n - 1; i++) {
        expected_current = expected_current->next;
    }
    expected_current->next = expected_current->next->next;

    struct ListNode *result = removeNthFromEnd(head, n);

    struct ListNode *current = result;
    struct ListNode *expected_current = expected_head;
    while (current != NULL && expected_current != NULL) {
        assert(current->val == expected_current->val);
        current = current->next;
        expected_current = expected_current->next;
    }
    assert(current == NULL && expected_current == NULL);

    free_linked_list(head);
    free_linked_list(expected_head);
}

void combined_proof_harness() {
    proof_harness_removeNthFromEnd();
}