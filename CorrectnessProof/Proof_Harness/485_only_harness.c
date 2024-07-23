void combined_proof_harness() {
    proof_harness_max();
    proof_harness_findMaxConsecutiveOnes();
    proof_harness_main();
}

void proof_harness_findMaxConsecutiveOnes() {
    int numsSize;
    __CPROVER_assume(numsSize >= 0);
    int* nums = (int*)malloc(sizeof(int) * numsSize);
    __CPROVER_assume(nums != NULL);
    for (int i = 0; i < numsSize; i++) {
        __CPROVER_assume(nums[i] >= 0);
        __CPROVER_assume(nums[i] <= 1);
    }

void proof_harness_max() {
    int a;
    int b;
    __CPROVER_assume(a >= 0);
    __CPROVER_assume(b >= 0);
    int expected = (a > b) ? a : b;
    int result = max(a, b);
    assert(result == expected);
}

void proof_harness_main() {
    int argc = 1;
    char** argv = (char**)malloc(sizeof(char*));
    __CPROVER_assume(argv != NULL);
    argv[0] = "program_name";
    main(argc, argv);
    free(argv);
}

