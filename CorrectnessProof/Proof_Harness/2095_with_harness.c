#include <assert.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* deleteMiddle(struct ListNode* head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    struct ListNode *fast, *slow, *prev;
    int n = 0;
    fast = head;
    slow = head;
    while (fast != NULL)
    {
        n = n + 1;
        fast = fast->next;
    }
    fast = head;
    while (fast->next != NULL && fast->next->next != NULL)  // finds mid node
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if (n % 2 == 0)
    {
        prev = slow;
        slow = slow->next;
        prev->next = slow->next;
    }
    else
        prev->next = slow->next;
    return head;
}

struct ListNode* create_list(int n) {
  struct ListNode* head = NULL;
  struct ListNode* current = NULL;
  for (int i = 0; i < n; i++) {
    struct ListNode* new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
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
  return head;
}

void proof_harness_deleteMiddle() {
  int n;
  __CPROVER_assume(n >= 0);
  struct ListNode* head = create_list(n);
  struct ListNode* result = deleteMiddle(head);
  // Check the result
  if (n == 0 || n == 1) {
    assert(result == NULL);
  } else {
    assert(result != NULL);
    // Check if the middle node is deleted
    int count = 0;
    struct ListNode* current = result;
    while (current != NULL) {
      count++;
      current = current->next;
    }
    if (n % 2 == 0) {
      assert(count == n - 1);
    } else {
      assert(count == n - 1);
    }
  }
  // Free the list
  struct ListNode* current = head;
  while (current != NULL) {
    struct ListNode* next = current->next;
    free(current);
    current = next;
  }
}

void proof_harness_main() {
  // No input to main, only call other proof harnesses
  proof_harness_deleteMiddle();
}

void combined_proof_harness() {
  proof_harness_main();
}