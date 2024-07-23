#include <assert.h>
#include <stdlib.h>

// Fucntion to calculate min of values a and b
int min(int a, int b) { return ((a < b) ? a : b); }

// Two pointer approach to find maximum container area
int maxArea(int *height, int heightSize)
{
    // Start with maximum container width
    int start = 0;
    int end = heightSize - 1;
    int res = 0;

    while (start < end)
    {
        // Calculate current area by taking minimum of two heights
        int currArea = (end - start) * min(height[start], height[end]);

        if (currArea > res)
            res = currArea;

        if (height[start] < height[end])
            start = start + 1;
        else
            end = end - 1;
    }

    return res;
}

void proof_harness_min() {
    int a;
    int b;
    __CPROVER_assume(a >= 0);
    __CPROVER_assume(b >= 0);
    int result = min(a, b);
    assert(result <= a);
    assert(result <= b);
    assert((result == a || result == b));
}

void proof_harness_maxArea() {
    int heightSize;
    __CPROVER_assume(heightSize >= 0);
    int *height = (int *)malloc(sizeof(int) * heightSize);
    __CPROVER_assume(height != NULL);
    for (int i = 0; i < heightSize; i++) {
        __CPROVER_assume(height[i] >= 0);
    }
    int result = maxArea(height, heightSize);
    free(height);
}

void proof_harness_main() {
    int heightSize;
    __CPROVER_assume(heightSize >= 0);
    int *height = (int *)malloc(sizeof(int) * heightSize);
    __CPROVER_assume(height != NULL);
    for (int i = 0; i < heightSize; i++) {
        __CPROVER_assume(height[i] >= 0);
    }
    int result = maxArea(height, heightSize);
    free(height);
}

void combined_proof_harness() {
    proof_harness_min();
    proof_harness_maxArea();
    proof_harness_main();
}