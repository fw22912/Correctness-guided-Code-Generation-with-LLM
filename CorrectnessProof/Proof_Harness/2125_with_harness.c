#include <assert.h>
#include <string.h>
#include <stdlib.h>

int coundDevices(char* bankRow){
    int result = 0;
    int bankRowSize = strlen(bankRow);
    for(int i = 0; i < bankRowSize; i++){
        if (bankRow[i] == '1'){
            result++;
        }
    }

    return result;
}

// Counting devices in each row
// Runtime: O(n*m), n-number of bank rows, m - max size of row.
// Space: O(1)
int numberOfBeams(char ** bank, int bankSize){
    int prevRowDevices = 0;
    int result = 0;
    for(int i = 0; i < bankSize; i++){
        int devices = coundDevices(bank[i]);
        if (devices == 0){
            continue;
        }

        result += devices * prevRowDevices;
        prevRowDevices = devices;
    }

    return result;
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

    int expected_result = 0;
    for (int i = 0; i < bankRowSize; i++) {
        if (bankRow[i] == '1') {
            expected_result++;
        }
    }

    int result = coundDevices(bankRow);
    assert(result == expected_result);

    free(bankRow);
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
    }

    int expected_result = 0;
    int prevRowDevices = 0;
    for (int i = 0; i < bankSize; i++) {
        int devices = 0;
        for (int j = 0; j < strlen(bank[i]); j++) {
            if (bank[i][j] == '1') {
                devices++;
            }
        }
        if (devices != 0) {
            expected_result += devices * prevRowDevices;
            prevRowDevices = devices;
        }
    }

    int result = numberOfBeams(bank, bankSize);
    assert(result == expected_result);

    for (int i = 0; i < bankSize; i++) {
        free(bank[i]);
    }
    free(bank);
}

void proof_harness_main() {
    // This harness function should be empty as main doesn't return anything.
}

void combined_proof_harness() {
    proof_harness_coundDevices();
    proof_harness_numberOfBeams();
    proof_harness_main();
}