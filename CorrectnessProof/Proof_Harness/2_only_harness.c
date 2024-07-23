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

void combined_proof_harness() {
    proof_harness_addTwoNumbers();
}

