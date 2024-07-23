#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// Count one's from right. Each step from right side decrease for one for each 1's and increase from left:
// 1001*0101  -> left: 4 + 1, right: 2 + 4
// 10010*101  -> left: (4+1) + (1+1), right: (2-1) + (4-1)
// Runtime: O(n)
// Space: O(1)
int* minOperations(char* boxes, int* returnSize){
    int leftOnes = 0;
    int leftCommonDistance = 0;
    
    int rightOnes = 0;
    int rightCommonDistance = 0;
    
    int boxesLength = strlen(boxes);

    *returnSize = boxesLength;
    int* result = malloc(boxesLength * sizeof(int));
    
    for (int i = 0; i < boxesLength; i++){
        if (boxes[i] == '1'){
            rightOnes += 1;
            rightCommonDistance += i;
        }
    }
    
    for (int i = 0; i < boxesLength; i++){
        if (boxes[i] == '1'){
            rightOnes -= 1;
            leftOnes += 1;
        }
        
        result[i] = rightCommonDistance + leftCommonDistance;
        rightCommonDistance -= rightOnes;
        leftCommonDistance += leftOnes;
    }

    return result;
}

void proof_harness_minOperations() {
    char *boxes;
    int returnSize;
    int boxesLength;
    
    boxesLength = __CPROVER_nondet_int();
    __CPROVER_assume(boxesLength > 0);
    
    boxes = (char*)malloc((boxesLength + 1) * sizeof(char));
    __CPROVER_assume(boxes != NULL);
    
    for (int i = 0; i < boxesLength; i++) {
        boxes[i] = __CPROVER_nondet_char();
        __CPROVER_assume(boxes[i] == '0' || boxes[i] == '1');
    }
    boxes[boxesLength] = '\0';
    
    int *result = minOperations(boxes, &returnSize);
    
    __CPROVER_assert(returnSize == boxesLength, "returnSize should be equal to boxesLength");
    
    for (int i = 0; i < boxesLength; i++) {
        int operations = 0;
        for (int j = 0; j < boxesLength; j++) {
            if (boxes[j] == '1') {
                operations += abs(i - j);
            }
        }
        __CPROVER_assert(result[i] == operations, "result[i] should be equal to the number of operations for box i");
    }
    
    free(boxes);
    free(result);
}

void proof_harness_main() {
    char *boxes;
    int returnSize;
    int boxesLength;
    
    boxesLength = __CPROVER_nondet_int();
    __CPROVER_assume(boxesLength > 0);
    
    boxes = (char*)malloc((boxesLength + 1) * sizeof(char));
    __CPROVER_assume(boxes != NULL);
    
    for (int i = 0; i < boxesLength; i++) {
        boxes[i] = __CPROVER_nondet_char();
        __CPROVER_assume(boxes[i] == '0' || boxes[i] == '1');
    }
    boxes[boxesLength] = '\0';
    
    int *result = minOperations(boxes, &returnSize);
    
    __CPROVER_assert(returnSize == boxesLength, "returnSize should be equal to boxesLength");
    
    for (int i = 0; i < boxesLength; i++) {
        int operations = 0;
        for (int j = 0; j < boxesLength; j++) {
            if (boxes[j] == '1') {
                operations += abs(i - j);
            }
        }
        __CPROVER_assert(result[i] == operations, "result[i] should be equal to the number of operations for box i");
    }
    
    free(boxes);
    free(result);
}

void combined_proof_harness() {
    proof_harness_minOperations();
    proof_harness_main();
}