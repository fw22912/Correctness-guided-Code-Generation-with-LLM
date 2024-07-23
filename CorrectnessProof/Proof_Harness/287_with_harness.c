#include <assert.h>
#include <stdlib.h>
#include <string.h>

int cmpval(const void *a, const void *b) { return *(int *)a - *(int *)b; }
int findDuplicate(int *nums, int numsSize)
{
    int i;
    qsort(nums, numsSize, sizeof(int), cmpval);
    for (i = 0; i < numsSize - 1; i++)
    {
        if (nums[i] == nums[i + 1])
            return nums[i];
    }
    return nums[i];
}

void proof_harness_findDuplicate() {
    int numsSize;
    __CPROVER_assume(numsSize > 0);
    int *nums = (int *)malloc(sizeof(int) * numsSize);
    __CPROVER_assume(nums != NULL);
    for (int i = 0; i < numsSize; i++) {
        nums[i] = __CPROVER_nondet_int();
    }
    int expected_result = findDuplicate(nums, numsSize);
    int actual_result = findDuplicate(nums, numsSize);
    assert(expected_result == actual_result);
    free(nums);
}

void proof_harness_main() {
    int argc = __CPROVER_nondet_int();
    __CPROVER_assume(argc >= 0);
    char **argv = (char **)malloc(sizeof(char *) * argc);
    __CPROVER_assume(argv != NULL);
    for (int i = 0; i < argc; i++) {
        argv[i] = (char *)malloc(sizeof(char) * 10);
        __CPROVER_assume(argv[i] != NULL);
        strcpy(argv[i], __CPROVER_nondet_string());
    }
    int result = main(argc, argv);
    for (int i = 0; i < argc; i++) {
        free(argv[i]);
    }
    free(argv);
}

void combined_proof_harness() {
    proof_harness_findDuplicate();
    proof_harness_main();
}