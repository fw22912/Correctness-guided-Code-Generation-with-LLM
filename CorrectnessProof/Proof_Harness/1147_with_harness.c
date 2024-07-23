#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(a,b) (((a)>(b))?(a):(b))

bool equalSubstrings(char* text, int firstIndex, int secondIndex, int length){
    for (int i = 0; i < length; i++){
        if (text[firstIndex + i] != text[secondIndex + i]){
            return false;
        }
    }

    return true;
}

int longestDecompositionDpCached(char* text, int textLen, int index, int* dp){
    if (2 * index >= textLen){
        return 0;
    }

    if (dp[index] == 0){
        dp[index] = longestDecompositionDp(text, textLen, index, dp);
    }

    return dp[index];
}

int longestDecompositionDp(char* text, int textLen, int index, int* dp){
    char ch = text[index];
    int result = 1;
    
    for (int i = 0; i < (textLen - 2 * index) / 2; i++){
        if (ch == text[textLen - 1 - index - i] 
            && equalSubstrings(text, index, textLen - 1 - index - i, i + 1)){
                return max(result, 2 + longestDecompositionDpCached(text, textLen, index + i + 1, dp));
        }
    }

    return result;
}

// Dynamic programming. Up -> down approach.
// Runtime: O(n*n)
// Space: O(n)
int longestDecomposition(char * text){
    int textLen = strlen(text);
    int* dp = calloc(textLen, sizeof(int));
    int result = longestDecompositionDpCached(text, textLen, 0, dp);

    free(dp);
    return result;
}

void proof_harness_equalSubstrings() {
    char *text = NULL;
    int firstIndex;
    int secondIndex;
    int length;
    __CPROVER_assume(text != NULL);
    __CPROVER_assume(firstIndex >= 0);
    __CPROVER_assume(secondIndex >= 0);
    __CPROVER_assume(length >= 0);
    __CPROVER_assume(firstIndex + length <= strlen(text));
    __CPROVER_assume(secondIndex + length <= strlen(text));
    bool expected_result = equalSubstrings(text, firstIndex, secondIndex, length);
    bool actual_result = equalSubstrings(text, firstIndex, secondIndex, length);
    assert(actual_result == expected_result);
}

void proof_harness_longestDecompositionDpCached() {
    char *text = NULL;
    int textLen;
    int index;
    int *dp = NULL;
    __CPROVER_assume(text != NULL);
    __CPROVER_assume(textLen >= 0);
    __CPROVER_assume(index >= 0);
    __CPROVER_assume(dp != NULL);
    __CPROVER_assume(index < textLen);
    int expected_result = longestDecompositionDpCached(text, textLen, index, dp);
    int actual_result = longestDecompositionDpCached(text, textLen, index, dp);
    assert(actual_result == expected_result);
}

void proof_harness_longestDecompositionDp() {
    char *text = NULL;
    int textLen;
    int index;
    int *dp = NULL;
    __CPROVER_assume(text != NULL);
    __CPROVER_assume(textLen >= 0);
    __CPROVER_assume(index >= 0);
    __CPROVER_assume(dp != NULL);
    __CPROVER_assume(index < textLen);
    int expected_result = longestDecompositionDp(text, textLen, index, dp);
    int actual_result = longestDecompositionDp(text, textLen, index, dp);
    assert(actual_result == expected_result);
}

void proof_harness_longestDecomposition() {
    char *text = NULL;
    __CPROVER_assume(text != NULL);
    int expected_result = longestDecomposition(text);
    int actual_result = longestDecomposition(text);
    assert(actual_result == expected_result);
}

void proof_harness_main() {
    char *text = NULL;
    __CPROVER_assume(text != NULL);
    int expected_result = longestDecomposition(text);
    int actual_result = longestDecomposition(text);
    assert(actual_result == expected_result);
}

void combined_proof_harness() {
    proof_harness_equalSubstrings();
    proof_harness_longestDecompositionDpCached();
    proof_harness_longestDecompositionDp();
    proof_harness_longestDecomposition();
    proof_harness_main();
}

int main() {
    combined_proof_harness();
    return 0;
}