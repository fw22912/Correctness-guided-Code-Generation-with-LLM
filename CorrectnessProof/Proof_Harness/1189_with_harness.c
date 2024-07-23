#include <assert.h>
#include <stdlib.h>
#include <string.h>

int maxNumberOfBalloons(char *text)
{
    /*
        0 -> b,
        1 -> a,
        2 -> l,
        3 -> o,
        4 -> n
    */
    int count_letters[5] = {0};
    int i, min_counter_ballons;

    for (char *ptr = text; *ptr; ptr++)
    {
        if (*ptr == 'b')
        {
            count_letters[0]++;
        }
        else if (*ptr == 'a')
        {
            count_letters[1]++;
        }
        else if (*ptr == 'l')
        {
            count_letters[2]++;
        }
        else if (*ptr == 'o')
        {
            count_letters[3]++;
        }
        else if (*ptr == 'n')
        {
            count_letters[4]++;
        }
    }

    /* Divide by 2 the repeted letters */
    count_letters[2] /= 2;
    count_letters[3] /= 2;

    /* Max number of times which we can write ballon is equal to min value of
     * letters on count_letter */
    min_counter_ballons = count_letters[0];
    for (i = 1; i < 5; i++)
    {
        if (count_letters[i] < min_counter_ballons)
            min_counter_ballons = count_letters[i];
    }

    return min_counter_ballons;
}

void proof_harness_maxNumberOfBalloons() {
    char *text;
    int expected_result;
    text = (char *)malloc(1024 * sizeof(char));
    __CPROVER_assume(text != NULL);
    __CPROVER_assume(strlen(text) <= 1023);
    expected_result = maxNumberOfBalloons(text);
    int result = maxNumberOfBalloons(text);
    assert(result == expected_result);
    free(text);
}

int main() {
    char *text;
    int result;
    text = (char *)malloc(1024 * sizeof(char));
    __CPROVER_assume(text != NULL);
    __CPROVER_assume(strlen(text) <= 1023);
    result = maxNumberOfBalloons(text);
    free(text);
    return 0;
}

void proof_harness_main() {
    char *text;
    int result;
    text = (char *)malloc(1024 * sizeof(char));
    __CPROVER_assume(text != NULL);
    __CPROVER_assume(strlen(text) <= 1023);
    result = maxNumberOfBalloons(text);
    free(text);
}

void combined_proof_harness() {
    proof_harness_maxNumberOfBalloons();
    proof_harness_main();
}