void combined_proof_harness() {
    proof_harness_pairSum();
}

void proof_harness_pairSum() {
    struct ListNode *head = NULL;
    __CPROVER_assume(head != NULL);
    int result = pairSum(head);
    free(head);
}

