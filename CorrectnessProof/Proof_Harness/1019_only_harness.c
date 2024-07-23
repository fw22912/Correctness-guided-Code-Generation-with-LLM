void combined_proof_harness() {
    proof_harness_nextLargerNodes();
}

void proof_harness_nextLargerNodes() {
    struct ListNode *head = NULL;
    int returnSize;
    int *output = nextLargerNodes(head, &returnSize);
    free(output);
}

