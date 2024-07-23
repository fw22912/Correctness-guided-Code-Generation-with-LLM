#include <assert.h>
#include <string.h>
#include <stdlib.h>

int lengthOfLongestSubstring(char *str)
{
    int n = strlen(str);

    if (!n)
        return 0;

    int L_len = 1;  // length of longest substring
    int C_len = 1;  // length of current substring

    int P_ind, i;      //  P_ind for previous index
    int visited[256];  //  visited will keep track of visiting char for the last
                       //  instance. since there are 256 ASCII char, its size is
                       //  limited to that value.
    memset(visited, -1, sizeof(int) * 256);
    visited[str[0]] =
        0;  //  the index of that char will tell us that when it was visited.
    for (i = 1; i < n; i++)
    {
        P_ind = visited[str[i]];
        if (P_ind == -1 || i - C_len > P_ind)
            C_len++;  //  if the current char was not visited earlier, or it is
                      //  not the part of current substring
        else
        {  //  otherwise, we need to change the current/longest substring length
            if (C_len > L_len)
                L_len = C_len;
            C_len = i - P_ind;
        }
        visited[str[i]] = i;
    }
    if (C_len > L_len)
        L_len = C_len;
    return L_len;
}
/* Brute force */
int lengthOfLongestSubstring(char *s)
{
    int cur_max = 0, max = 0;
    int counter[255];
    int end = 0;

    memset(counter, 0, sizeof(int) * 255);
    while (end < strlen(s))
    {
        if (counter[s[end]] == 0)
        {
            counter[s[end]]++;
            end++;
            cur_max++;
        }
        else
        {
            char c = s[end];
            memset(counter, 0, 255 * sizeof(int));
            if (cur_max >= max)
                max = cur_max;
            cur_max = 0;
            while (s[end - 1] != c) end--;
        }
    }
    if (cur_max >= max)
        max = cur_max;
    return max;
}

void proof_harness_lengthOfLongestSubstring() {
    char *str = (char *)malloc(1024 * sizeof(char));
    __CPROVER_assume(str != NULL);

    int n = __CPROVER_nondet_int();
    __CPROVER_assume(n >= 0 && n < 1024);
    for (int i = 0; i < n; i++) {
        str[i] = (char)__CPROVER_nondet_int();
    }
    str[n] = '\0';

    int result = lengthOfLongestSubstring(str);
    // Check for any potential overflows or out-of-bounds accesses
    // Add assertions based on your understanding of the function's behavior

    free(str);
}

void proof_harness_lengthOfLongestSubstring_brute_force() {
    char *s = (char *)malloc(1024 * sizeof(char));
    __CPROVER_assume(s != NULL);

    int n = __CPROVER_nondet_int();
    __CPROVER_assume(n >= 0 && n < 1024);
    for (int i = 0; i < n; i++) {
        s[i] = (char)__CPROVER_nondet_int();
    }
    s[n] = '\0';

    int result = lengthOfLongestSubstring(s);
    // Check for any potential overflows or out-of-bounds accesses
    // Add assertions based on your understanding of the function's behavior

    free(s);
}

void combined_proof_harness() {
    proof_harness_lengthOfLongestSubstring();
    proof_harness_lengthOfLongestSubstring_brute_force();
}