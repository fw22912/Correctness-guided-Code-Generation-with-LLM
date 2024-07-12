void proof_harness_duplicateNumber() {
    size_t n;
    __CPROVER_assume(n >= 2);
    uint32_t *in_arr = (uint32_t *)malloc(sizeof(uint32_t) * n);
    __CPROVER_assume(in_arr != NULL);

    //  Ensure that the input array contains at least one duplicate number.
    uint32_t duplicate = 0;
    __CPROVER_assume(duplicate >= 1 && duplicate <= n);
    for (size_t i = 0; i < n; i++) {
      if (i == duplicate) {
        in_arr[i] = duplicate;
      }

