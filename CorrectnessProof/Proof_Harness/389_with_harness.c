#include <assert.h>
#include <string.h>
#include <stdlib.h>

char findTheDifference(char *s, char *t)
{
    int sum1 = 0, sum2 = 0;
    int i;
    for (i = 0; i < strlen(s); i++) sum1 += s[i];
    for (i = 0; i < strlen(t); i++) sum2 += t[i];
    return (char)(sum2 - sum1);
}

void proof_harness_findTheDifference() {
    char *s = (char *)malloc(100 * sizeof(char));
    __CPROVER_assume(s != NULL);
    char *t = (char *)malloc(100 * sizeof(char));
    __CPROVER_assume(t != NULL);
    int s_len = __CPROVER_nondet_int();
    __CPROVER_assume(s_len >= 0 && s_len < 100);
    int t_len = __CPROVER_nondet_int();
    __CPROVER_assume(t_len >= 0 && t_len < 100);
    for (int i = 0; i < s_len; i++) {
        s[i] = (char)__CPROVER_nondet_int();
    }
    s[s_len] = '\0';
    for (int i = 0; i < t_len; i++) {
        t[i] = (char)__CPROVER_nondet_int();
    }
    t[t_len] = '\0';
    char expected_result = findTheDifference(s, t);
    char actual_result = findTheDifference(s, t);
    assert(expected_result == actual_result);
    free(s);
    free(t);
}

int main() {
    proof_harness_findTheDifference();
    return 0;
}

void combined_proof_harness() {
    proof_harness_findTheDifference();
}