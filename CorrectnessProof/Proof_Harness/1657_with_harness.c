#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const charLength = 26;

int* charsCount(char* word){
    int* result = calloc(charLength, sizeof(int));
    int wordLen = strlen(word);
    for (int i = 0; i < wordLen; i++){
        result[word[i] - 'a']++;
    }

    return result;
}

int diff(const int *i, const int *j)
{
    return *i - *j;
}

// Counting
// Runtime: O(n)
// Space: O(1)
bool closeStrings(char * word1, char * word2){
    int* word1CharsCounter = charsCount(word1);
    int* word2CharsCounter = charsCount(word2);

    // The lengths of both string should be equal
    if (strlen(word1) != strlen(word2)){
        return false;
    }

    // The char should appear in both strings
    for (int i = 0; i < charLength; i++){
        if ((word1CharsCounter[i] != 0 && word2CharsCounter[i] == 0) ||
           (word1CharsCounter[i] == 0 && word2CharsCounter[i] != 0)){
               return false;
           }
    }

    qsort(word1CharsCounter, charLength, sizeof (int), (int(*) (const void *, const void *)) diff);
    qsort(word2CharsCounter, charLength, sizeof (int), (int(*) (const void *, const void *)) diff);

    // appearing of chars should be the same in both strings.
    for (int i = 0; i < charLength; i++){
        if (word1CharsCounter[i] != word2CharsCounter[i]){
               return false;
        }
    }

    free(word1CharsCounter);
    free(word2CharsCounter);
    return true;
}

void proof_harness_charsCount(){
    char* word = (char*)malloc(100 * sizeof(char));
    __CPROVER_assume(word != NULL);
    
    int* result = charsCount(word);
    
    free(word);
    free(result);
}

void proof_harness_diff(){
    int i;
    int j;

    int* p_i = &i;
    int* p_j = &j;
    int result = diff(p_i, p_j);
    
}

void proof_harness_closeStrings(){
    char* word1 = (char*)malloc(100 * sizeof(char));
    __CPROVER_assume(word1 != NULL);
    
    char* word2 = (char*)malloc(100 * sizeof(char));
    __CPROVER_assume(word2 != NULL);
    
    bool result = closeStrings(word1, word2);
    
    free(word1);
    free(word2);
}

void proof_harness_main(){
    char* word1 = (char*)malloc(100 * sizeof(char));
    __CPROVER_assume(word1 != NULL);
    
    char* word2 = (char*)malloc(100 * sizeof(char));
    __CPROVER_assume(word2 != NULL);
    
    int result = closeStrings(word1, word2);
    
    free(word1);
    free(word2);
}

void combined_proof_harness(){
    proof_harness_charsCount();
    proof_harness_diff();
    proof_harness_closeStrings();
    proof_harness_main();
}