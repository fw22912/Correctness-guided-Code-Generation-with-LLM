#include <assert.h>
#include <stdlib.h>

/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *head = NULL;
    struct ListNode *walk = NULL;
    struct ListNode *tmp = NULL;

    int carry = 0;
    int val1 = 0;
    int val2 = 0;
    int val = 0;

    while (l1 != NULL || l2 != NULL || carry)
    {
        val1 = 0;
        val2 = 0;
        val = 0;

        if (l1)
        {
            val1 = l1->val;
            l1 = l1->next;
        }

        if (l2)
        {
            val2 = l2->val;
            l2 = l2->next;
        }

        val = carry + val1 + val2;
        carry = val / 10;

        tmp = malloc(sizeof(struct ListNode));
        tmp->val = val % 10;
        tmp->next = NULL;

        if (!head)
        {
            head = walk = tmp;
        }
        else
        {
            walk->next = tmp;
            walk = walk->next;
        }
    }

    return head;
}

struct ListNode *create_list_node(int val) {
    struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

struct ListNode *create_linked_list(int *arr, int size) {
    struct ListNode *head = NULL;
    struct ListNode *tail = NULL;
    for (int i = 0; i < size; i++) {
        struct ListNode *node = create_list_node(arr[i]);
        if (head == NULL) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }
    return head;
}

void free_linked_list(struct ListNode *head) {
    struct ListNode *curr = head;
    while (curr != NULL) {
        struct ListNode *next = curr->next;
        free(curr);
        curr = next;
    }
}

void proof_harness_addTwoNumbers() {
    int l1_arr_size;
    int l2_arr_size;
    __CPROVER_assume(l1_arr_size >= 0);
    __CPROVER_assume(l2_arr_size >= 0);

    int *l1_arr = (int *)malloc(sizeof(int) * l1_arr_size);
    int *l2_arr = (int *)malloc(sizeof(int) * l2_arr_size);

    for (int i = 0; i < l1_arr_size; i++) {
        __CPROVER_assume(l1_arr[i] >= 0 && l1_arr[i] <= 9);
    }

    for (int i = 0; i < l2_arr_size; i++) {
        __CPROVER_assume(l2_arr[i] >= 0 && l2_arr[i] <= 9);
    }

    struct ListNode *l1 = create_linked_list(l1_arr, l1_arr_size);
    struct ListNode *l2 = create_linked_list(l2_arr, l2_arr_size);

    struct ListNode *result = addTwoNumbers(l1, l2);

    free(l1_arr);
    free(l2_arr);

    free_linked_list(l1);
    free_linked_list(l2);
    free_linked_list(result);
}

void combined_proof_harness() {
    proof_harness_addTwoNumbers();
}