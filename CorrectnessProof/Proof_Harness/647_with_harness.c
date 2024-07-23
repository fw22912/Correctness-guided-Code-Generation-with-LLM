#include <assert.h>
#include <string.h>
#include <stdlib.h>

/* Author : Saurav Dubey */

int countSubstrings(char *s)
{
    int len = strlen(s);
    int i;
    int count = 0;
    for (i = 0; i < len; i++)
    {
        // cases handled for both odd and even lenghted Palindrome

        count += countPalin(s, i, i, len);
        if (i != len - 1)
            count += countPalin(s, i, i + 1, len);
    }
    return count;
}
int countPalin(char *s, int head, int tail, int len)
{
    int ret = (s[head] == s[tail]) ? 1 : 0;
    if (ret && head - 1 >= 0 && tail + 1 < len)
        ret += countPalin(s, head - 1, tail + 1, len);
    return ret;
}

void proof_harness_countPalin() {
    char *s = (char *)malloc(100 * sizeof(char));
    __CPROVER_assume(s != NULL);
    int head = __CPROVER_nondet_int();
    int tail = __CPROVER_nondet_int();
    int len = __CPROVER_nondet_int();
    __CPROVER_assume(head >= 0 && head < len);
    __CPROVER_assume(tail >= 0 && tail < len);
    __CPROVER_assume(len > 0);
    int ret_expected = (s[head] == s[tail]) ? 1 : 0;
    if (ret_expected && head - 1 >= 0 && tail + 1 < len)
        ret_expected += countPalin(s, head - 1, tail + 1, len);
    int ret_actual = countPalin(s, head, tail, len);
    assert(ret_actual == ret_expected);
    free(s);
}

void proof_harness_countSubstrings() {
    char *s = (char *)malloc(100 * sizeof(char));
    __CPROVER_assume(s != NULL);
    int len = strlen(s);
    int i;
    int count_expected = 0;
    for (i = 0; i < len; i++)
    {
        // cases handled for both odd and even lenghted Palindrome

        count_expected += countPalin(s, i, i, len);
        if (i != len - 1)
            count_expected += countPalin(s, i, i + 1, len);
    }
    int count_actual = countSubstrings(s);
    assert(count_actual == count_expected);
    free(s);
}

void proof_harness_main() {
    char *s = (char *)malloc(100 * sizeof(char));
    __CPROVER_assume(s != NULL);
    int count_expected = countSubstrings(s);
    int count_actual = countSubstrings(s);
    assert(count_actual == count_expected);
    free(s);
}

void combined_proof_harness() {
    proof_harness_countPalin();
    proof_harness_countSubstrings();
    proof_harness_main();
}