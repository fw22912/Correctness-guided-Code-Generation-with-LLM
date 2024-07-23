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

void proof_harness_unionSet(){
    int setsSize;
    __CPROVER_assume(setsSize > 0);
    int* sets = malloc(setsSize * sizeof(int));
    __CPROVER_assume(sets != NULL);
    for (int i = 0; i < setsSize; i++) {
        sets[i] = __CPROVER_nondet_int();
    }

void combined_proof_harness(){
    proof_harness_find();
    proof_harness_unionSet();
    proof_harness_findRedundantConnection();
}

void proof_harness_find(){
    int setsSize;
    __CPROVER_assume(setsSize > 0);
    int* sets = malloc(setsSize * sizeof(int));
    __CPROVER_assume(sets != NULL);
    for (int i = 0; i < setsSize; i++) {
        sets[i] = __CPROVER_nondet_int();
    }

