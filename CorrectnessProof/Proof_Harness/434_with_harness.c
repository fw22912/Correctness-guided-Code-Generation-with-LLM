#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Given a string s, returns the number of segments in the string.
int countSegments(char * s){
    int sLen = strlen(s);
    int prevSpace = 1;
    int result = 0;
    char currChar;

    for (int i = 0; i < sLen; i++){
        currChar = s[i];

        //A string of whitespaces will only be counted once as the condition below is only true when we transition from whitespace to non-whitespace.
        //Since we start with assumed whitespace (prevSpace = 1), initial whitespaces are handled as well, if any
        if (s[i] != ' ' && prevSpace) {
            result++;
        }
        prevSpace = (currChar == ' ');
    }

    return result;
}

void proof_harness_countSegments() {
    char *s = (char *)malloc(100 * sizeof(char));
    __CPROVER_assume(s != NULL);
    
    int sLen;
    __CPROVER_assume(sLen >= 0 && sLen <= 100);
    
    for (int i = 0; i < sLen; i++) {
        s[i] = (char)__CPROVER_choice_int(256);
    }
    
    int expectedResult = 0;
    for (int i = 0; i < sLen; i++) {
        if (i == 0 && s[i] != ' ') expectedResult++;
        if (i > 0 && s[i] != ' ' && s[i-1] == ' ') expectedResult++;
    }
    
    int result = countSegments(s);
    assert(result == expectedResult);
    
    free(s);
}


void proof_harness_main() {
    char *s = (char *)malloc(100 * sizeof(char));
    __CPROVER_assume(s != NULL);
    
    int sLen;
    __CPROVER_assume(sLen >= 0 && sLen <= 100);
    
    for (int i = 0; i < sLen; i++) {
        s[i] = (char)__CPROVER_choice_int(256);
    }
    
    int expectedResult = 0;
    for (int i = 0; i < sLen; i++) {
        if (i == 0 && s[i] != ' ') expectedResult++;
        if (i > 0 && s[i] != ' ' && s[i-1] == ' ') expectedResult++;
    }
    
    int result = countSegments(s);
    assert(result == expectedResult);
    
    free(s);
}

void combined_proof_harness() {
    proof_harness_countSegments();
    proof_harness_main();
}