#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int compare(const int* i, const int* j)
{
    return *i - *j;
}

// Sorting.
// Runtime: O(n*log(n))
// Space: O(n)
int maximumBags(int* capacity, int capacitySize, int* rocks, int rocksSize, int additionalRocks) {
    int* capacityLeft = malloc(capacitySize * sizeof(int));
    for (int i = 0; i < capacitySize; i++) {
        capacityLeft[i] = capacity[i] - rocks[i];
    }

    qsort(capacityLeft, capacitySize, sizeof (int), (int(*) (const void*, const void*)) compare);
    
    int bags = 0;
    for (int i = 0; i < capacitySize; i++) {
        if (additionalRocks < capacityLeft[i]){
            break;
        }

        additionalRocks -= capacityLeft[i];
        bags++;
    }

    free(capacityLeft);
    return bags;
}

void proof_harness_compare() {
    int *i = (int *)malloc(sizeof(int));
    __CPROVER_assume(i != NULL);  // Ensure i is not NULL
    int *j = (int *)malloc(sizeof(int));
    __CPROVER_assume(j != NULL);  // Ensure j is not NULL
    
    *i = __CPROVER_nondet_int();
    *j = __CPROVER_nondet_int();

    int result = compare(i, j);
    
    free(i);
    free(j);
}

void proof_harness_maximumBags() {
    int capacitySize = __CPROVER_nondet_int();
    __CPROVER_assume(capacitySize > 0);
    int *capacity = (int *)malloc(capacitySize * sizeof(int));
    __CPROVER_assume(capacity != NULL);  // Ensure capacity is not NULL
    for (int i = 0; i < capacitySize; i++) {
        capacity[i] = __CPROVER_nondet_int();
    }

    int rocksSize = __CPROVER_nondet_int();
    __CPROVER_assume(rocksSize > 0);
    __CPROVER_assume(rocksSize == capacitySize);
    int *rocks = (int *)malloc(rocksSize * sizeof(int));
    __CPROVER_assume(rocks != NULL);  // Ensure rocks is not NULL
    for (int i = 0; i < rocksSize; i++) {
        rocks[i] = __CPROVER_nondet_int();
        __CPROVER_assume(rocks[i] <= capacity[i]);
    }

    int additionalRocks = __CPROVER_nondet_int();
    int result = maximumBags(capacity, capacitySize, rocks, rocksSize, additionalRocks);
    
    free(capacity);
    free(rocks);
}

void proof_harness_main() {
    int capacitySize = __CPROVER_nondet_int();
    __CPROVER_assume(capacitySize > 0);
    int *capacity = (int *)malloc(capacitySize * sizeof(int));
    __CPROVER_assume(capacity != NULL);  // Ensure capacity is not NULL
    for (int i = 0; i < capacitySize; i++) {
        capacity[i] = __CPROVER_nondet_int();
    }

    int rocksSize = __CPROVER_nondet_int();
    __CPROVER_assume(rocksSize > 0);
    __CPROVER_assume(rocksSize == capacitySize);
    int *rocks = (int *)malloc(rocksSize * sizeof(int));
    __CPROVER_assume(rocks != NULL);  // Ensure rocks is not NULL
    for (int i = 0; i < rocksSize; i++) {
        rocks[i] = __CPROVER_nondet_int();
        __CPROVER_assume(rocks[i] <= capacity[i]);
    }

    int additionalRocks = __CPROVER_nondet_int();
    int result = maximumBags(capacity, capacitySize, rocks, rocksSize, additionalRocks);
    
    free(capacity);
    free(rocks);
}

void combined_proof_harness() {
    proof_harness_compare();
    proof_harness_maximumBags();
    proof_harness_main();
}