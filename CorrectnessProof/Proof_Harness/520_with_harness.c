#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bool detectCapitalUse(char *word)
{
    int len = strlen(word);
    if (len == 1)
        return 1;
    int countUpper = 0, i;
    for (i = 0; i < len; i++)
    {
        if (isupper(word[i]))
            countUpper++;
    }
    /* All lower case */
    if (countUpper == 0)
        return 1;
    /* 1st character is upper, and the rest is lower case */
    if (countUpper == 1 && isupper(word[0]))
        return 1;
    /* Check all character is upper case? */
    else
        return countUpper == len;
}

/* Another way */
bool isAllUpper(char *word)
{
    int len = strlen(word);
    for (int i = 0; i < len; i++)
    {
        if (islower(word[i]))
            return 0;
    }
    return 1;
}
bool detectCapitalUse(char *word)
{
    int len = strlen(word);
    for (int i = 1; i < len; i++)
    {
        if (isupper(word[i]) && !isAllUpper(word))
            return 0;
    }
    return 1;
}


void proof_harness_detectCapitalUse() {
    char *word = (char *)malloc(100 * sizeof(char));
    __CPROVER_assume(word != NULL); 
    
    int len = __CPROVER_nondet_int(); 
    __CPROVER_assume(len >= 0 && len <= 100); 
    
    for (int i = 0; i < len; i++) {
        word[i] = __CPROVER_nondet_char(); 
    }
    word[len] = '\0';
    
    bool expected_result = detectCapitalUse(word); 
    bool actual_result = detectCapitalUse(word); 
    assert(expected_result == actual_result);
    free(word);
}

void proof_harness_isAllUpper() {
    char *word = (char *)malloc(100 * sizeof(char));
    __CPROVER_assume(word != NULL); 
    
    int len = __CPROVER_nondet_int(); 
    __CPROVER_assume(len >= 0 && len <= 100); 
    
    for (int i = 0; i < len; i++) {
        word[i] = __CPROVER_nondet_char(); 
    }
    word[len] = '\0';
    
    bool expected_result = isAllUpper(word); 
    bool actual_result = isAllUpper(word); 
    assert(expected_result == actual_result);
    free(word);
}

void proof_harness_detectCapitalUse() {
    char *word = (char *)malloc(100 * sizeof(char));
    __CPROVER_assume(word != NULL); 
    
    int len = __CPROVER_nondet_int(); 
    __CPROVER_assume(len >= 0 && len <= 100); 
    
    for (int i = 0; i < len; i++) {
        word[i] = __CPROVER_nondet_char(); 
    }
    word[len] = '\0';
    
    bool expected_result = detectCapitalUse(word); 
    bool actual_result = detectCapitalUse(word); 
    assert(expected_result == actual_result);
    free(word);
}

void combined_proof_harness() {
    proof_harness_detectCapitalUse();
    proof_harness_isAllUpper();
    proof_harness_detectCapitalUse();
}

int main() {
    combined_proof_harness();
    return 0;
}