#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int diff(const int* i, const int* j)

{
    return *i - *j;
}


// Sorting.
// Runtime: O(n*log(n))
// Space: O(1)
int hIndex(int* citations, int citationsSize){
    qsort(citations, citationsSize, sizeof(int), (int(*) (const void*, const void*)) diff);

    for(int i = 0; i < citationsSize; i++){
        if (citations[citationsSize - 1 - i] <= i){
            return i;
        }
    }

    return citationsSize;
}


void proof_harness_diff() {
    int *i = (int *)malloc(sizeof(int));
    __CPROVER_assume(i != NULL);
    int *j = (int *)malloc(sizeof(int));
    __CPROVER_assume(j != NULL);
    int result = diff(i, j);
    free(i);
    free(j);
}

void proof_harness_hIndex() {
    int citationsSize;
    __CPROVER_assume(citationsSize >= 0);
    int *citations = (int *)malloc(sizeof(int) * citationsSize);
    __CPROVER_assume(citations != NULL);
    int result = hIndex(citations, citationsSize);
    free(citations);
}

void proof_harness_main() {
    int argc;
    __CPROVER_assume(argc >= 0);
    char **argv = (char **)malloc(sizeof(char *) * argc);
    __CPROVER_assume(argv != NULL);
    for (int i = 0; i < argc; i++) {
        argv[i] = (char *)malloc(sizeof(char) * 1024);
        __CPROVER_assume(argv[i] != NULL);
    }
    int result = main(argc, argv);
    for (int i = 0; i < argc; i++) {
        free(argv[i]);
    }
    free(argv);
}

void combined_proof_harness() {
    proof_harness_diff();
    proof_harness_hIndex();
    proof_harness_main();
}