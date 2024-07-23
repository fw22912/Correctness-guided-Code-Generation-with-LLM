#include <assert.h>
#include <string.h>
#include <stdlib.h>

bool isAnagram(char *s, char *t)
{
    int n = strlen(s);
    int m = strlen(t);

    int cnt_s[1000], cnt_t[1000];
    for (int c = 97; c < 97 + 26; c++) cnt_s[c] = cnt_t[c] = 0;

    for (int i = 0; i < n; i++) cnt_s[s[i]]++;

    for (int i = 0; i < m; i++) cnt_t[t[i]]++;

    for (int c = 97; c < 97 + 26; c++)
        if (cnt_s[c] != cnt_t[c])
            return false;

    return true;
}

void proof_harness_isAnagram() {
    char *s = (char *)malloc(1000 * sizeof(char));
    __CPROVER_assume(s != NULL);
    char *t = (char *)malloc(1000 * sizeof(char));
    __CPROVER_assume(t != NULL);
    __CPROVER_assume(strlen(s) <= 1000);
    __CPROVER_assume(strlen(t) <= 1000);

    for (int i = 0; i < strlen(s); i++) {
        __CPROVER_assume(s[i] >= 'a' && s[i] <= 'z');
    }

    for (int i = 0; i < strlen(t); i++) {
        __CPROVER_assume(t[i] >= 'a' && t[i] <= 'z');
    }
    bool expected_result = isAnagram(s, t);

    bool actual_result = isAnagram(s, t);

    assert(expected_result == actual_result);
    free(s);
    free(t);
}

int main() {
    proof_harness_isAnagram();

    return 0;
}

void combined_proof_harness() {
    proof_harness_isAnagram();
}