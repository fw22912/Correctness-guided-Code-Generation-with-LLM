#include <assert.h>
#include <string.h>
#include <stdlib.h>

long numberOfWaysForChar(char * s, char c){
    long firstBuildingAppearNumber = 0;
    long secondBuildingAppearNumber = 0;
    long result = 0;
    
    int sLength = strlen(s);
    for (int i = 0; i < sLength; i++){
        if (s[i] == c){
            result += secondBuildingAppearNumber;

            firstBuildingAppearNumber += 1;
            continue;
        }

        secondBuildingAppearNumber += firstBuildingAppearNumber;
    }
    
    return result;
        
}

// numberOfWays returns the sum of number ways of selecting first building
// and the number of ways of selecting second building which gives us the
// number of ways of selecting three building such that no
// consecutive buildings are in the same category.
// Runtime: O(n)
// Space: O(n)
long long numberOfWays(char * s){
    return numberOfWaysForChar(s, '0') + numberOfWaysForChar(s, '1');
}

void proof_harness_numberOfWaysForChar() {
    char *s = (char *)malloc(100 * sizeof(char));
    __CPROVER_assume(s != NULL);
    char c;
    __CPROVER_assume(c == '0' || c == '1');

    int sLength;
    __CPROVER_assume(sLength >= 0 && sLength <= 100);

    for (int i = 0; i < sLength; i++) {
        __CPROVER_assume(s[i] == '0' || s[i] == '1');
    }

    long expectedResult = 0;
    long firstBuildingAppearNumber = 0;
    long secondBuildingAppearNumber = 0;

    for (int i = 0; i < sLength; i++){
        if (s[i] == c){
            expectedResult += secondBuildingAppearNumber;

            firstBuildingAppearNumber += 1;
            continue;
        }

        secondBuildingAppearNumber += firstBuildingAppearNumber;
    }

    long result = numberOfWaysForChar(s, c);
    assert(result == expectedResult);

    free(s);
}


void proof_harness_numberOfWays() {
    char *s = (char *)malloc(100 * sizeof(char));
    __CPROVER_assume(s != NULL);

    int sLength;
    __CPROVER_assume(sLength >= 0 && sLength <= 100);

    for (int i = 0; i < sLength; i++) {
        __CPROVER_assume(s[i] == '0' || s[i] == '1');
    }

    long long expectedResult = numberOfWaysForChar(s, '0') + numberOfWaysForChar(s, '1');
    long long result = numberOfWays(s);

    assert(result == expectedResult);

    free(s);
}

void proof_harness_main() {
    char *s = (char *)malloc(100 * sizeof(char));
    __CPROVER_assume(s != NULL);

    int sLength;
    __CPROVER_assume(sLength >= 0 && sLength <= 100);

    for (int i = 0; i < sLength; i++) {
        __CPROVER_assume(s[i] == '0' || s[i] == '1');
    }

    long long result = numberOfWays(s);

    free(s);
}

void combined_proof_harness() {
    proof_harness_numberOfWaysForChar();
    proof_harness_numberOfWays();
    proof_harness_main();
}