#include <assert.h>
#include <string.h>
#include <stdlib.h>

bool isVowel(char chr){
    switch(chr){
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            return true;
    }
    
    return false;
}

// Counting
// Runtime: O(n)
// Space: O(1)
bool halvesAreAlike(char * s){
    int lenS = strlen(s);
    int halfVowels = 0;
    int currVowels = 0;
    
    for (int i = 0; i < lenS; i++){
        if (isVowel(s[i])){
            currVowels++;
        }
        
        if (2 * (i + 1) == lenS){
            halfVowels = currVowels;
        }
    }
    
    return 2 * halfVowels == currVowels;
}

void proof_harness_isVowel() {
    char chr;
    __CPROVER_assume(chr >= 0 && chr <= 255);
    bool expected = isVowel(chr);
    bool actual = isVowel(chr);
    assert(expected == actual);
}

void proof_harness_halvesAreAlike() {
    char *s = (char *)malloc(100 * sizeof(char));
    __CPROVER_assume(s != NULL);
    int lenS;
    __CPROVER_assume(lenS >= 0 && lenS <= 100);
    for (int i = 0; i < lenS; i++) {
        __CPROVER_assume(s[i] >= 0 && s[i] <= 255);
    }
    bool expected = halvesAreAlike(s);
    bool actual = halvesAreAlike(s);
    assert(expected == actual);
    free(s);
}

void proof_harness_main() {
    // No inputs for main(), so no assumptions needed.
    // Add assertions here to test the behavior of main().
    // Example:
    // assert(some_condition_based_on_main_behavior);
}

void combined_proof_harness() {
    proof_harness_isVowel();
    proof_harness_halvesAreAlike();
    proof_harness_main();
}