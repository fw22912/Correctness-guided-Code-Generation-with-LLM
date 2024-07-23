void combined_proof_harness() {
    proof_harness_coundDevices();
    proof_harness_numberOfBeams();
    proof_harness_main();
}

void proof_harness_main() {
    // This harness function should be empty as main doesn't return anything.
}

void proof_harness_coundDevices() {
    char *bankRow = (char *)malloc(sizeof(char) * 10);
    __CPROVER_assume(bankRow != NULL);
    int bankRowSize;
    __CPROVER_assume(bankRowSize >= 0);
    __CPROVER_assume(bankRowSize < 10);
    for (int i = 0; i < bankRowSize; i++) {
        __CPROVER_assume(bankRow[i] == '0' || bankRow[i] == '1');
    }

void proof_harness_numberOfBeams() {
    int bankSize;
    __CPROVER_assume(bankSize >= 0);
    char **bank = (char **)malloc(sizeof(char *) * bankSize);
    __CPROVER_assume(bank != NULL);
    for (int i = 0; i < bankSize; i++) {
        int rowSize;
        __CPROVER_assume(rowSize >= 0);
        bank[i] = (char *)malloc(sizeof(char) * rowSize);
        __CPROVER_assume(bank[i] != NULL);
        for (int j = 0; j < rowSize; j++) {
            __CPROVER_assume(bank[i][j] == '0' || bank[i][j] == '1');
        }

