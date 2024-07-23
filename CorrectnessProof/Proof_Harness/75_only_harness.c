void proof_harness_swap() {
    int *x = (int *)malloc(sizeof(int));
    __CPROVER_assume(x != NULL);
    int *y = (int *)malloc(sizeof(int));
    __CPROVER_assume(y != NULL);
    int initial_x = *x;
    int initial_y = *y;
    swap(x, y);
    if (x == y) {
        assert(*x == initial_x);
        assert(*y == initial_y);
    }

void proof_harness_sortColors() {
    int n;
    __CPROVER_assume(n >= 0);
    int *arr = (int *)malloc(sizeof(int) * n);
    __CPROVER_assume(arr != NULL);
    for (int i = 0; i < n; i++) {
        __CPROVER_assume(arr[i] >= 0 && arr[i] <= 2);
    }

void combined_proof_harness() {
    proof_harness_swap();
    proof_harness_sortColors();
}

