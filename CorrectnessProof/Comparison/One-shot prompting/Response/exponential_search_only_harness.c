void proof_harness_binary_search() {
    uint16_t l_index, r_index;
    int64_t n;
    __CPROVER_assume(l_index >= 0);
    __CPROVER_assume(l_index <= 65535);
    __CPROVER_assume(r_index >= 0);
    __CPROVER_assume(r_index <= 65535);
    __CPROVER_assume(l_index <= r_index);

    uint16_t length = r_index - l_index + 1;

    int64_t *arr = (int64_t *)malloc(sizeof(int64_t) * length);
    __CPROVER_assume(arr != NULL);

    for (uint16_t i = 0; i < length; i++) {
        arr[i] = i * 2;
    }

void proof_harness_exponential_search() {
    uint16_t length;
    int64_t n;
    __CPROVER_assume(length >= 0);
    __CPROVER_assume(length <= 65535);

    int64_t *arr = (int64_t *)malloc(sizeof(int64_t) * length);
    __CPROVER_assume(arr != NULL);

    for (uint16_t i = 0; i < length; i++) {
        arr[i] = i * 2;
    }

