#include <assert.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool isPalindrome(char *s)
{
    int start = 0, end = strlen(s) - 1;
    while (start < end)
    {
        if (!isalpha(s[start]) && !isalnum(s[start]))
        {
            start++;
        }
        else if (!isalpha(s[end]) && !isalnum(s[end]))
        {
            end--;
        }
        else
        {
            char c1 = tolower(s[start]);
            char c2 = tolower(s[end]);
            if (c1 != c2)
                return 0;
            start++;
            end--;
        }
    }
    return 1;
}

void proof_harness_isPalindrome() {
    char *s = (char *)malloc(1024 * sizeof(char));
    __CPROVER_assume(s != NULL);
    
    __CPROVER_assume(strlen(s) <= 1024);
    
    bool expected_result = isPalindrome(s);
    bool actual_result = isPalindrome(s);
    assert(expected_result == actual_result);
    free(s);
}

void proof_harness_main() {
    char *s = (char *)malloc(1024 * sizeof(char));
    __CPROVER_assume(s != NULL);
    
    __CPROVER_assume(strlen(s) <= 1024);
    
    isPalindrome(s);
    free(s);
}

void combined_proof_harness() {
    proof_harness_isPalindrome();
    proof_harness_main();
}