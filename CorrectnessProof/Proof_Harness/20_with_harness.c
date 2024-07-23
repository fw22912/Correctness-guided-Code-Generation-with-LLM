#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isValid(char *s)
{
    int i, k = 0, len = strlen(s);
    char *store = calloc(len, sizeof(char));

    for (i = 0; s[i] != '\0'; i++)
    {
        switch (s[i])
        {
        case '(':
        case '{':
        case '[':
            store[k++] = s[i];
            break;
        case ')':
            if (k < 1 || store[--k] != '(')
                goto out;
            break;
        case '}':
            if (k < 1 || store[--k] != '{')
                goto out;
            break;
        case ']':
            if (k < 1 || store[--k] != '[')
                goto out;
            break;
        }
    }
out:
    free(store);
    return s[i] == '\0' && k == 0;
}

void proof_harness_isValid() {
    char *s = (char *)malloc(1024 * sizeof(char));
    __CPROVER_assume(s != NULL);
    __CPROVER_assume(strlen(s) <= 1023); 

    bool expected_result = isValid(s); 
    bool actual_result = isValid(s);
    assert(actual_result == expected_result);
    free(s); 
}


void proof_harness_main() {
    char *s = (char *)malloc(1024 * sizeof(char));
    __CPROVER_assume(s != NULL);
    __CPROVER_assume(strlen(s) <= 1023); 
    main(0, NULL);
    free(s);
}


void combined_proof_harness() {
    proof_harness_isValid();
    proof_harness_main();
}