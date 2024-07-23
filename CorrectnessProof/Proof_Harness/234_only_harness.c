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

void combined_proof_harness() {
    proof_harness_reverse();
    proof_harness_isPalindrome();
}

