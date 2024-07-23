void combined_proof_harness() {
    proof_harness_trap();
    proof_harness_main();
}

void proof_harness_main() {
    int argc = rand();
    char **argv = malloc(argc * sizeof(char *));
    __CPROVER_assume(argv != NULL);
    for (int i = 0; i < argc; i++) {
        argv[i] = NULL;
    }

void proof_harness_trap() {
    int heightSize;
    __CPROVER_assume(heightSize >= 0);
    int *height = malloc(heightSize * sizeof(int));
    __CPROVER_assume(height != NULL);
    for (int i = 0; i < heightSize; i++) {
        height[i] = rand();
    }

