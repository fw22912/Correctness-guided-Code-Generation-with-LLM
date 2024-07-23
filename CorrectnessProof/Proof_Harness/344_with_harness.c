#include <assert.h>
#include <stdlib.h>
#include <string.h>

void reverseString(char *s, int sSize)
{
    int last = sSize - 1, i;
    for (i = 0; i < last; i++)
    {
        char tmp = s[i];
        s[i] = s[last];
        s[last] = tmp;
        last--;
    }
}

void proof_harness_reverseString() {
    int sSize;
    __CPROVER_assume(sSize >= 0);
    char *s = (char *)malloc(sizeof(char) * sSize);
    __CPROVER_assume(s != NULL); 
    
    for (int i = 0; i < sSize; i++) {
        s[i] = (char)__CPROVER_nondet_int();
    }
    
    char *s_copy = (char *)malloc(sizeof(char) * sSize);
    __CPROVER_assume(s_copy != NULL);
    memcpy(s_copy, s, sSize);

    reverseString(s, sSize);

    for (int i = 0; i < sSize / 2; i++) {
        assert(s[i] == s_copy[sSize - i - 1]);
        assert(s[sSize - i - 1] == s_copy[i]);
    }

    if (sSize % 2 != 0) {
        assert(s[sSize / 2] == s_copy[sSize / 2]);
    }
    free(s);
    free(s_copy);
}

int main() {
    proof_harness_reverseString();
    return 0;
}

void combined_proof_harness() {
    proof_harness_reverseString();
}