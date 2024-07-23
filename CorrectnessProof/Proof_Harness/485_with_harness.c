#include <assert.h>
#include <stdlib.h>

int max(int a, int b){
    if(a>b)
        return a;
    else
        return b;
}

int findMaxConsecutiveOnes(int* nums, int numsSize){
    int count = 0; 
	int result = 0; 
    
    for (int i = 0; i < numsSize; i++)
	{
		if (nums[i] == 0)
			count = 0;
		else
		{
			count++;
			result = max(result, count);
		}
	}
    return result;
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

void proof_harness_findMaxConsecutiveOnes() {
    int numsSize;
    __CPROVER_assume(numsSize >= 0);
    int* nums = (int*)malloc(sizeof(int) * numsSize);
    __CPROVER_assume(nums != NULL);
    for (int i = 0; i < numsSize; i++) {
        __CPROVER_assume(nums[i] >= 0);
        __CPROVER_assume(nums[i] <= 1);
    }
    int expected = 0;
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            count = 0;
        } else {
            count++;
            expected = (count > expected) ? count : expected;
        }
    }
    int result = findMaxConsecutiveOnes(nums, numsSize);
    assert(result == expected);
    free(nums);
}

void proof_harness_main() {
    int argc = 1;
    char** argv = (char**)malloc(sizeof(char*));
    __CPROVER_assume(argv != NULL);
    argv[0] = "program_name";
    main(argc, argv);
    free(argv);
}

void combined_proof_harness() {
    proof_harness_max();
    proof_harness_findMaxConsecutiveOnes();
    proof_harness_main();
}