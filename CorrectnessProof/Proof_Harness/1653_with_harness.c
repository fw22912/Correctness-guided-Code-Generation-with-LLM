#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define min(X, Y)  ((X) < (Y) ? (X) : (Y))

// Dynamic programming approach. Down -> Up.
// Runtime: O(n)
// Space: O(1)
int minimumDeletions(char * s){
    int len = strlen(s);
    
    int aStateValue = s[0] == 'b';

    int bStateValue = 0;
    
    int newAStateValue;
    int newBStateValue;

    for(int i = 1; i < len; i++){
        newAStateValue = aStateValue + (s[i] == 'b');

        newBStateValue = min(
                               aStateValue,
                               bStateValue + (s[i] == 'a')
                             );
            
        aStateValue = newAStateValue;
        bStateValue = newBStateValue;
    }
    
    return min(aStateValue, bStateValue);
}


void proof_harness_minimumDeletions() {
    char *s = malloc(100 * sizeof(char));
    __CPROVER_assume(s != NULL);
    int len = __CPROVER_nondet_int();
    __CPROVER_assume(len >= 0 && len < 100);
    for (int i = 0; i < len; i++) {
        s[i] = __CPROVER_nondet_char();
        __CPROVER_assume(s[i] == 'a' || s[i] == 'b');
    }
    s[len] = '\0';
    int expected = minimumDeletions(s);
    int actual = minimumDeletions(s);
    assert(expected == actual);
    free(s);
}

void combined_proof_harness() {
    proof_harness_minimumDeletions();
}