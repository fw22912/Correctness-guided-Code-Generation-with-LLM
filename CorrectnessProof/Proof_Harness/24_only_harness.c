void combined_proof_harness() {
    proof_harness_swapPairs();
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
        }

