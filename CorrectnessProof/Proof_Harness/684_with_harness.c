#include <assert.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int find(int* sets, int index){
    while (sets[index] != index){
        index = sets[index];
    }

    return index;
}

void unionSet(int* sets, int i1, int i2){
    int i1Parent = find(sets, i1);
    int i2Parent = find(sets, i2);
    
    sets[i1Parent] = i2Parent;
}

// Union find
// Runtime: O(n)
// Space: O(n)
int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize){
    int setsSize = edgesSize + 1;
    int* sets = malloc(setsSize * sizeof(int));
    for (int i = 0; i < setsSize; i++){
        sets[i] = i;
    }

    int* result = malloc(2 * sizeof(int));
    *returnSize = 2;

    for (int i = 0; i < edgesSize; i++){
        int* edge = edges[i];

        int i0Parent = find(sets, edge[0]);
        int i1Parent = find(sets, edge[1]);

        if (i0Parent == i1Parent){
            result[0] = edge[0];
            result[1] = edge[1];
            continue;
        }

        unionSet(sets, i0Parent, i1Parent);
    }

    free(sets);
    return result;
}

void proof_harness_find(){
    int setsSize;
    __CPROVER_assume(setsSize > 0);
    int* sets = malloc(setsSize * sizeof(int));
    __CPROVER_assume(sets != NULL);
    for (int i = 0; i < setsSize; i++) {
        sets[i] = __CPROVER_nondet_int();
    }
    int index = __CPROVER_nondet_int();
    __CPROVER_assume(index >= 0 && index < setsSize);
    int expected_result = find(sets, index);
    int actual_result = find(sets, index);
    assert(expected_result == actual_result);
    free(sets);
}

void proof_harness_unionSet(){
    int setsSize;
    __CPROVER_assume(setsSize > 0);
    int* sets = malloc(setsSize * sizeof(int));
    __CPROVER_assume(sets != NULL);
    for (int i = 0; i < setsSize; i++) {
        sets[i] = __CPROVER_nondet_int();
    }
    int i1 = __CPROVER_nondet_int();
    __CPROVER_assume(i1 >= 0 && i1 < setsSize);
    int i2 = __CPROVER_nondet_int();
    __CPROVER_assume(i2 >= 0 && i2 < setsSize);
    unionSet(sets, i1, i2);
    free(sets);
}

void proof_harness_findRedundantConnection(){
    int edgesSize;
    __CPROVER_assume(edgesSize > 0);
    int** edges = malloc(edgesSize * sizeof(int*));
    __CPROVER_assume(edges != NULL);
    int* edgesColSize = malloc(edgesSize * sizeof(int));
    __CPROVER_assume(edgesColSize != NULL);
    for (int i = 0; i < edgesSize; i++) {
        edgesColSize[i] = 2;
        edges[i] = malloc(2 * sizeof(int));
        __CPROVER_assume(edges[i] != NULL);
        edges[i][0] = __CPROVER_nondet_int();
        edges[i][1] = __CPROVER_nondet_int();
    }
    int returnSize;
    int* result = findRedundantConnection(edges, edgesSize, edgesColSize, &returnSize);
    assert(returnSize == 2);
    for (int i = 0; i < edgesSize; i++) {
        free(edges[i]);
    }
    free(edges);
    free(edgesColSize);
    free(result);
}

void combined_proof_harness(){
    proof_harness_find();
    proof_harness_unionSet();
    proof_harness_findRedundantConnection();
}

int main(){
    combined_proof_harness();
    return 0;
}