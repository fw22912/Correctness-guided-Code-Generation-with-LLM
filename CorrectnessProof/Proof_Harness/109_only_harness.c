void combined_proof_harness() {
    proof_harness_buildBST();
    proof_harness_sortedListToBST();
}

void proof_harness_buildBST() {
    struct ListNode *head = NULL;
    struct ListNode *tail = NULL;
    __CPROVER_assume(head != NULL);
    __CPROVER_assume(tail != NULL);
    struct TreeNode *ret_val = buildBST(head, tail);
}

void proof_harness_sortedListToBST() {
    struct ListNode *head = NULL;
    __CPROVER_assume(head != NULL);
    struct TreeNode *ret_val = sortedListToBST(head);
}

