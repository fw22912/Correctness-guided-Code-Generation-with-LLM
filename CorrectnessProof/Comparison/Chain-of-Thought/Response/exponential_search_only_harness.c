void proof_harness_binary_search() {
    uint16_t l_index;
    uint16_t r_index;
    __CPROVER_assume(l_index >= 0 && l_index <= UINT16_MAX);
    __CPROVER_assume(r_index >= 0 && r_index <= UINT16_MAX);
    __CPROVER_assume(l_index <= r_index);

    uint16_t length = r_index - l_index + 1;
    int64_t* arr = malloc(sizeof(int64_t) * length);
    __CPROVER_assume(arr != NULL);
    for (uint16_t i = 0; i < length; i++) {
        arr[i] = __CPROVER_nondet_int64_t();
    }

void proof_harness_exponential_search() {
    uint16_t length;
    __CPROVER_assume(length >= 0 && length <= UINT16_MAX);

    int64_t* arr = malloc(sizeof(int64_t) * length);
    __CPROVER_assume(arr != NULL);
    for (uint16_t i = 0; i < length; i++) {
        arr[i] = __CPROVER_nondet_int64_t();
    }

