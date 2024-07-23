void combined_proof_harness() {
    proof_harness_reverseList();
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
        }

