#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

const int EnglishLettersNumber = 26;

void countCharsForStringSlice(int* charsCounter, char* s, int length, int sign) {
    for (int i = 0; i < length; i++) {

        charsCounter[s[i] - 'a'] += sign;
    }
}

// Sliding window
// Calculate number of chars in the current slide. 
// Runtime: O(n)
// Space: O(1) - only number of english lowercase letters.
bool checkInclusion(char* s1, char* s2) {
    int lengthS1 = strlen(s1);
    int lengthS2 = strlen(s2);

    if (lengthS1 > lengthS2) {

        return false;
    }

    int* charsCounter = calloc(EnglishLettersNumber, sizeof(int));

    // We keep counters of s1 with '-' sign. It has to be offset by s2 chars
    countCharsForStringSlice(charsCounter, s1, lengthS1, -1);
    countCharsForStringSlice(charsCounter, s2, lengthS1, 1);

    int diffChars = 0;
    for (int i = 0; i < EnglishLettersNumber; i++) {
        if (charsCounter[i] != 0) {
            diffChars++;
        }
    }

    if (diffChars == 0) {
        return true;
    }

    for (int i = 0; i < lengthS2 - lengthS1; i++) {
        int charNumberLeft = s2[i] - 'a';
        int charNumberRight = s2[i + lengthS1] - 'a'; 

        charsCounter[charNumberLeft] -= 1;
        if (charsCounter[charNumberLeft] == 0) {
            diffChars -= 1;
        }
        else if (charsCounter[charNumberLeft] == -1) {
            diffChars += 1;
        }

        charsCounter[charNumberRight] += 1;
        if (charsCounter[charNumberRight] == 0) {
            diffChars -= 1;
        }
        else if (charsCounter[charNumberRight] == 1) {
            diffChars += 1;
        }

        if (diffChars == 0) {
            return true;
        }
    }

    free(charsCounter);
    return false;
}


void proof_harness_countCharsForStringSlice() {
    int length;
    int sign;
    __CPROVER_assume(length >= 0);
    __CPROVER_assume(sign >= -128);
    __CPROVER_assume(sign <= 127);
    char* s = malloc(length);
    __CPROVER_assume(s != NULL);
    int* charsCounter = malloc(EnglishLettersNumber * sizeof(int));
    __CPROVER_assume(charsCounter != NULL);
    for (int i = 0; i < EnglishLettersNumber; i++) {
        charsCounter[i] = 0;
    }
    countCharsForStringSlice(charsCounter, s, length, sign);
    free(charsCounter);
    free(s);
}

void proof_harness_checkInclusion() {
    char* s1 = malloc(100);
    __CPROVER_assume(s1 != NULL);
    char* s2 = malloc(100);
    __CPROVER_assume(s2 != NULL);
    bool result = checkInclusion(s1, s2);
    free(s1);
    free(s2);
}

void combined_proof_harness() {
    proof_harness_countCharsForStringSlice();
    proof_harness_checkInclusion();
}

int main() {
    combined_proof_harness();
    return 0;
}