#include <assert.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char *toLowerCase(char *str)
{
    for (int i = 0; i < strlen(str); i++) str[i] = tolower(str[i]);
    return str;
}

void proof_harness_toLowerCase() {
    char *str = (char *)malloc(100 * sizeof(char));
    __CPROVER_assume(str != NULL);
    
    size_t len = __CPROVER_nondet_uint();
    __CPROVER_assume(len < 100);
    
    for (size_t i = 0; i < len; i++) {
        str[i] = __CPROVER_nondet_char();
    }
    str[len] = '\0';

    char *result = toLowerCase(str);

    for (size_t i = 0; i < len; i++) {
        if (isupper(str[i])) {
            assert(result[i] == tolower(str[i]));
        } else {
            assert(result[i] == str[i]);
        }
    }
    free(str);
}

int main() {
    return 0;
}

void proof_harness_main() {
    main();
}

void combined_proof_harness() {
    proof_harness_toLowerCase();
    proof_harness_main();
}