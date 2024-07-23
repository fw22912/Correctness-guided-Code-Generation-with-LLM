#include <assert.h>
#include <string.h>
#include <stdlib.h>

#define max(X, Y) ((X) > (Y) ? (X) : (Y))

int maximizeTarget(char * answerKey, char targetChar, int k){
    int leftIndex = -1;
    int result = 0;
    int currTargetChars = 0;
    int lenAnswerKey = strlen(answerKey);

    for (int rightIndex = 0; rightIndex < lenAnswerKey; rightIndex++){
        char ch = answerKey[rightIndex];
        if (ch == targetChar){
            currTargetChars++;
        }
        
        while (rightIndex - leftIndex > currTargetChars + k) {
            leftIndex++;
            if (answerKey[leftIndex] == targetChar){
                currTargetChars--;
            }
        }
        
        result = max(result, rightIndex - leftIndex);
    }
    
    return result;
}

// Use sliding window approach + two pointers.
// Runtime: O(n)
// Space: O(1)
int maxConsecutiveAnswers(char * answerKey, int k){
    return max(maximizeTarget(answerKey, 'T', k), maximizeTarget(answerKey, 'F', k));
}

void proof_harness_maximizeTarget() {
    char *answerKey = (char *)malloc(100 * sizeof(char));
    __CPROVER_assume(answerKey != NULL);  // Ensure answerKey is not NULL
    char targetChar;
    int k;

    __CPROVER_assume(k >= 0);
    __CPROVER_assume(k <= 100);

    int lenAnswerKey = __CPROVER_nondet_int();
    __CPROVER_assume(lenAnswerKey >= 0);
    __CPROVER_assume(lenAnswerKey <= 100);
    for (int i = 0; i < lenAnswerKey; i++) {
        answerKey[i] = __CPROVER_nondet_char();
    }
    targetChar = __CPROVER_nondet_char();

    int result = maximizeTarget(answerKey, targetChar, k);
    // Add assertions based on your understanding of the function's behavior
    // Example: 
    // assert(result >= 0 && result <= lenAnswerKey);

    free(answerKey);
}

void proof_harness_maxConsecutiveAnswers() {
    char *answerKey = (char *)malloc(100 * sizeof(char));
    __CPROVER_assume(answerKey != NULL);  // Ensure answerKey is not NULL
    int k;

    __CPROVER_assume(k >= 0);
    __CPROVER_assume(k <= 100);

    int lenAnswerKey = __CPROVER_nondet_int();
    __CPROVER_assume(lenAnswerKey >= 0);
    __CPROVER_assume(lenAnswerKey <= 100);
    for (int i = 0; i < lenAnswerKey; i++) {
        answerKey[i] = __CPROVER_nondet_char();
    }

    int result = maxConsecutiveAnswers(answerKey, k);
    // Add assertions based on your understanding of the function's behavior
    // Example: 
    // assert(result >= 0 && result <= lenAnswerKey);

    free(answerKey);
}

void proof_harness_main() {
    char *answerKey = (char *)malloc(100 * sizeof(char));
    __CPROVER_assume(answerKey != NULL);  // Ensure answerKey is not NULL
    int k;

    __CPROVER_assume(k >= 0);
    __CPROVER_assume(k <= 100);

    int lenAnswerKey = __CPROVER_nondet_int();
    __CPROVER_assume(lenAnswerKey >= 0);
    __CPROVER_assume(lenAnswerKey <= 100);
    for (int i = 0; i < lenAnswerKey; i++) {
        answerKey[i] = __CPROVER_nondet_char();
    }

    int result = maxConsecutiveAnswers(answerKey, k);
    // Add assertions based on your understanding of the function's behavior
    // Example: 
    // assert(result >= 0 && result <= lenAnswerKey);

    free(answerKey);
}

void combined_proof_harness() {
    proof_harness_maximizeTarget();
    proof_harness_maxConsecutiveAnswers();
    proof_harness_main();
}