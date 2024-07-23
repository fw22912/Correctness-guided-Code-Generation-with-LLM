#include <stdlib.h>
#include <string.h>
#include <assert.h>

char *get_letters(char digit) {
    switch (digit) {
        case '2':
            return "abc";
        case '3':
            return "def";
        case '4':
            return "ghi";
        case '5':
            return "jkl";
        case '6':
            return "mno";
        case '7':
            return "pqrs";
        case '8':
            return "tuv";
        case '9':
            return "wxyz";
        default:
            return "";
    }
}

char **letterCombinations(char *digits, int *return_size) {
    char *cp;
    int i, j, k, l, ind, k_tot, l_tot, digits_size = 0;

    if (*digits == '\0') {
        *return_size = 0;
        return NULL;
    }

    *return_size = 1;
    cp = digits;
    while (*cp != '\0') {
        *return_size *= strlen(get_letters(*cp));
        digits_size++;
        cp++;
    }

    char **combs = malloc(sizeof(char*) * (*return_size));
    for (i = 0; i < *return_size; i++) {
        combs[i] = malloc(sizeof(char) * (digits_size + 1));
        combs[i][digits_size] = '\0';
    }

    k_tot = 1;
    l_tot = (*return_size);
    for (i = 0; i < digits_size; i++) { // loop accross digits
        cp = get_letters(digits[i]);
        l_tot /= strlen(cp);
        for (j = 0; j < strlen(cp); j++) { // loop accross letters of the digit
            for (k = 0; k < k_tot; k++) { // loop across the subset starting positions for each letter
                for (l = 0; l < l_tot; l++) { // loop accross each subset positions for each letter
                    ind = k * l_tot * strlen(cp) + l + l_tot * j;
                    combs[ind][i] = cp[j];
                }
            }
        }
        k_tot *= strlen(cp);
    }

    return combs;
}

void proof_harness_get_letters() {
    char digit;
    __CPROVER_assume(digit >= '0' && digit <= '9');
    char *result = get_letters(digit);
    if (digit >= '2' && digit <= '9') {
        assert(strlen(result) > 0);
    } else {
        assert(strlen(result) == 0);
    }
}

void proof_harness_letterCombinations() {
    char *digits = malloc(10);
    __CPROVER_assume(digits != NULL);
    int return_size;
    int digits_size = 0;
    char *cp = digits;
    while(*cp != '\0') {
        __CPROVER_assume(*cp >= '2' && *cp <= '9');
        digits_size++;
        cp++;
    }
    char **combs = letterCombinations(digits, &return_size);
    if (digits_size == 0) {
        assert(combs == NULL);
        assert(return_size == 0);
    } else {
        assert(combs != NULL);
        assert(return_size > 0);
        for (int i = 0; i < return_size; i++) {
            assert(strlen(combs[i]) == digits_size);
            for (int j = 0; j < digits_size; j++) {
                assert(combs[i][j] >= 'a' && combs[i][j] <= 'z');
            }
        }
    }
    free(digits);
    for (int i = 0; i < return_size; i++) {
        free(combs[i]);
    }
    free(combs);
}


void proof_harness_main() {
    char *digits = malloc(10);
    __CPROVER_assume(digits != NULL);
    int return_size;
    char **combs = letterCombinations(digits, &return_size);
    if (combs == NULL) {
        assert(return_size == 0);
    } else {
        assert(return_size > 0);
    }
    free(digits);
    for (int i = 0; i < return_size; i++) {
        free(combs[i]);
    }
    free(combs);
}

void combined_proof_harness() {
    proof_harness_get_letters();
    proof_harness_letterCombinations();
    proof_harness_main();
}