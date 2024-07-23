#include <string.h>
#include <assert.h>
#include <stdlib.h>

int numJewelsInStones(char *j, char *s)
{
    // as strlen is O(n), store it once rather than using it in for loop
    int cnt[500], lens = strlen(s), lenj = strlen(j), sol = 0;
    memset(cnt, 0, sizeof(cnt));

    // lookup to know which character occurs in j
    for (int i = 0; i < lenj; i++) cnt[j[i]]++;

    // count the characters in s
    for (int i = 0; i < lens; i++) sol += cnt[s[i]];

    return sol;
}

void proof_harness_numJewelsInStones() {
    char *j = (char *)malloc(500 * sizeof(char));
    __CPROVER_assume(j != NULL);
    char *s = (char *)malloc(500 * sizeof(char));
    __CPROVER_assume(s != NULL);

    int expected_result;
    __CPROVER_assume(strlen(j) > 0);
    __CPROVER_assume(strlen(s) > 0);

    expected_result = numJewelsInStones(j, s);

    int actual_result = numJewelsInStones(j, s);
    assert(actual_result == expected_result);
    
    free(j);
    free(s);
}

void combined_proof_harness() {
    proof_harness_numJewelsInStones();
}

int main() {
    combined_proof_harness();
    return 0;
}