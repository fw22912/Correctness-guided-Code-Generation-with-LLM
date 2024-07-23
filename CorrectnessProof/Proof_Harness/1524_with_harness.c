#include <assert.h>
#include <stdlib.h>

// Counting whole summ. evens sums number and odd summs number.
// Runtime: O(n),
// Space: O(1)
int numOfSubarrays(int* arr, int arrSize){
    int result = 0;
    int curSumm = 0;
    int currOddSumms = 0;
    int currEvenSumm = 0;
    int modulo = 1000000000 + 7;

    for(int i = 0; i < arrSize; i++){
        curSumm += arr[i];
        if (curSumm % 2 == 0){
            currEvenSumm++;
            result = (result + currOddSumms) % modulo;
        }
        else {
            currOddSumms++;
            result = (result + 1 + currEvenSumm) % modulo;
        }
    }

    return result % modulo;
}

void proof_harness_numOfSubarrays() {
    int arrSize;
    __CPROVER_assume(arrSize >= 0);
    int* arr = (int*)malloc(sizeof(int) * arrSize);
    __CPROVER_assume(arr != NULL); 
    for (int i = 0; i < arrSize; i++) {
        arr[i] = __CPROVER_nondet_int();
    }

    int expected_result = numOfSubarrays(arr, arrSize);
    int result = numOfSubarrays(arr, arrSize);
    assert(result == expected_result);
    free(arr);
}

void proof_harness_main() {
    int arrSize;
    __CPROVER_assume(arrSize >= 0);
    int* arr = (int*)malloc(sizeof(int) * arrSize);
    __CPROVER_assume(arr != NULL); 
    for (int i = 0; i < arrSize; i++) {
        arr[i] = __CPROVER_nondet_int();
    }

    int result = numOfSubarrays(arr, arrSize);
    free(arr);
}


void combined_proof_harness() {
    proof_harness_numOfSubarrays();
    proof_harness_main();
}