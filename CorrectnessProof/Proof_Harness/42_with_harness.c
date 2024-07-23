#define max(x,y)(((x)>(y))?(x):(y))
#define min(x,y)(((x)<(y))?(x):(y))

// Max stack. Runtime: O(n), Space: O(n)
// Algorithm description: 
// - Calculate the stack of maximums from right board.
// - For each index find left maximum and right maximum of height
// - The each index if heights could place nor greater than minimum of left and right max minus curr height
// - Sum all index in result
int trap(int* height, int heightSize){
    int* rightMaxStack = malloc(heightSize * sizeof(int));
    rightMaxStack[heightSize - 1] = height[heightSize - 1];

    for (int i = heightSize - 2; i >= 0; i--){
        rightMaxStack[i] = max(rightMaxStack[i + 1], height[i]);
    }

    int leftMax = 0;
    int result = 0;
    for (int i = 0; i < heightSize; i++){
        leftMax = max(leftMax, height[i]);
        result += max(0, min(leftMax, rightMaxStack[i]) - height[i]);
    }
    
    free(rightMaxStack);
    return result;
}

#include <assert.h>
#include <stdlib.h>

void proof_harness_trap() {
    int heightSize;
    __CPROVER_assume(heightSize >= 0);
    int *height = malloc(heightSize * sizeof(int));
    __CPROVER_assume(height != NULL);
    for (int i = 0; i < heightSize; i++) {
        height[i] = rand();
    }
    int result = trap(height, heightSize);
    free(height);
}

void proof_harness_main() {
    int argc = rand();
    char **argv = malloc(argc * sizeof(char *));
    __CPROVER_assume(argv != NULL);
    for (int i = 0; i < argc; i++) {
        argv[i] = NULL;
    }
    main(argc, argv);
    free(argv);
}

void combined_proof_harness() {
    proof_harness_trap();
    proof_harness_main();
}