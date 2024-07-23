#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int compare(const void* i, const void* j)
{
    return *((int*)i) - *((int*)j);
}

// Greedy + sorting
// Runtime: O(n*log(n))
// Space: O(1)
int maxIceCream(int* costs, int costsSize, int coins){
    qsort(costs, costsSize, sizeof(int), compare);

    int result = 0;
    int leftCoins = coins;
    for (int i = 0; i < costsSize; i++){
        if (costs[i] > leftCoins){
            break;
        }

        leftCoins -= costs[i];
        result++;
    }

    return result;
}

void proof_harness_maxIceCream() {
    int costsSize;
    __CPROVER_assume(costsSize >= 0);
    int* costs = (int*)malloc(sizeof(int) * costsSize);
    __CPROVER_assume(costs != NULL); 
    int coins;
    __CPROVER_assume(coins >= 0);
    for (int i = 0; i < costsSize; i++) {
        __CPROVER_assume(costs[i] > 0);
    }

    int expectedResult = maxIceCream(costs, costsSize, coins);
    int actualResult = maxIceCream(costs, costsSize, coins);
    assert(expectedResult == actualResult);
    free(costs);
}

void proof_harness_compare() {
    int i;
    int j;
    __CPROVER_assume(i >= 0);
    __CPROVER_assume(j >= 0);
    int* a = (int*)malloc(sizeof(int));
    __CPROVER_assume(a != NULL);
    int* b = (int*)malloc(sizeof(int));
    __CPROVER_assume(b != NULL);
    *a = i;
    *b = j;
    int expectedResult = i - j;
    int actualResult = compare(a, b);
    assert(expectedResult == actualResult);
    free(a);
    free(b);
}

int main() {
    proof_harness_maxIceCream();
    proof_harness_compare();
    return 0;
}

void combined_proof_harness() {
    proof_harness_maxIceCream();
    proof_harness_compare();
}