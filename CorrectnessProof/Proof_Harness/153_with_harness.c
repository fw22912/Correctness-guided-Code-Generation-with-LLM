#include <assert.h>
#include <stdlib.h>

int findMin(int *nums, int numsSize)
{
    int low = 0, high = numsSize - 1;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        /* minimum is on left side */
        if (nums[mid] < nums[high])
            high = mid;
        /* minimum is on right side */
        else
            low = mid + 1;
    }
    return nums[low];
}

void proof_harness_findMin() {
    int numsSize;
    __CPROVER_assume(numsSize > 0);
    int *nums = (int *)malloc(sizeof(int) * numsSize);
    __CPROVER_assume(nums != NULL);
    for (int i = 0; i < numsSize; i++) {
        nums[i] = __CPROVER_nondet_int();
    }
    int expected_result = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < expected_result) {
            expected_result = nums[i];
        }
    }
    int result = findMin(nums, numsSize);
    assert(result == expected_result);
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
        __CPROVER_assume(argv[i][0] != '\0');
        for (int j = 1; j < 10; j++) {
            argv[i][j] = __CPROVER_nondet_char();
        }
        argv[i][9] = '\0';
    }
    main(argc, argv);
    for (int i = 0; i < argc; i++) {
        free(argv[i]);
    }
    free(argv);
}

void combined_proof_harness() {
    proof_harness_findMin();
    proof_harness_main();
}