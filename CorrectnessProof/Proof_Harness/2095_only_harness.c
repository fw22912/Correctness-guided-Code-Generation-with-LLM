void combined_proof_harness() {
  proof_harness_main();
}

void proof_harness_deleteMiddle() {
  int n;
  __CPROVER_assume(n >= 0);
  struct ListNode* head = create_list(n);
  struct ListNode* result = deleteMiddle(head);
  // Check the result
  if (n == 0 || n == 1) {
    assert(result == NULL);
  }

void proof_harness_main() {
  // No input to main, only call other proof harnesses
  proof_harness_deleteMiddle();
}

