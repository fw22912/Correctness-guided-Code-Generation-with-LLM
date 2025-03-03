#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/** Recursive implementation
 * \param[in] arr array to search
 * \param l left index of search range
 * \param r right index of search range
 * \param x target value to search for
 * \returns location of x assuming array arr[l..r] is present
 * \returns -1 otherwise
 */
int binarysearch1(const int *arr, int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        // If element is present at middle
        if (arr[mid] == x)
            return mid;

        // If element is smaller than middle
        if (arr[mid] > x)
            return binarysearch1(arr, l, mid - 1, x);

        // Else element is in right subarray
        return binarysearch1(arr, mid + 1, r, x);
    }

    // When element is not present in array
    return -1;
}

/** Iterative implementation
 * \param[in] arr array to search
 * \param l left index of search range
 * \param r right index of search range
 * \param x target value to search for
 * \returns location of x assuming array arr[l..r] is present
 * \returns -1 otherwise
 */
int binarysearch2(const int *arr, int l, int r, int x)
{
    int mid = l + (r - l) / 2;

    while (arr[mid] != x)
    {
        if (r <= l || r < 0)
            return -1;

        if (arr[mid] > x)
            // If element is smaller than middle
            r = mid - 1;
        else
            // Else element is in right subarray
            l = mid + 1;

        mid = l + (r - l) / 2;
    }

    // When element is not present in array
    return mid;
}

/** Test implementations */
void test()
{
    // give function an array to work with
    int arr[] = {2, 3, 4, 10, 40};
    // get size of array
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Test 1.... ");
    // set value to look for
    int x = 10;
    // set result to what is returned from binarysearch
    int result = binarysearch1(arr, 0, n - 1, x);
    assert(result == 3);
    printf("passed recursive... ");
    result = binarysearch2(arr, 0, n - 1, x);
    assert(result == 3);
    printf("passed iterative...\n");

    printf("Test 2.... ");
    x = 5;
    // set result to what is returned from binarysearch
    result = binarysearch1(arr, 0, n - 1, x);
    assert(result == -1);
    printf("passed recursive... ");
    result = binarysearch2(arr, 0, n - 1, x);
    assert(result == -1);
    printf("passed iterative...\n");
}

/** Main function */
int main(void)
{
    test();
    return 0;
}

void proof_harness_binarysearch1() {
    int *arr;
    int l;
    int r;
    int x;
    int n;

    arr = (int *)malloc(sizeof(int) * 10);
    __CPROVER_assume(arr != NULL);
    n = __CPROVER_nondet_int();
    __CPROVER_assume(n >= 0 && n <= 10);
    for (int i = 0; i < n; i++) {
        arr[i] = __CPROVER_nondet_int();
    }
    l = __CPROVER_nondet_int();
    __CPROVER_assume(l >= 0 && l < n);
    r = __CPROVER_nondet_int();
    __CPROVER_assume(r >= 0 && r < n);
    __CPROVER_assume(l <= r);
    x = __CPROVER_nondet_int();

    int result = binarysearch1(arr, l, r, x);

    if (result != -1) {
        assert(arr[result] == x);
    }

    free(arr);
}

void proof_harness_binarysearch2() {
    int *arr;
    int l;
    int r;
    int x;
    int n;

    arr = (int *)malloc(sizeof(int) * 10);
    __CPROVER_assume(arr != NULL);
    n = __CPROVER_nondet_int();
    __CPROVER_assume(n >= 0 && n <= 10);
    for (int i = 0; i < n; i++) {
        arr[i] = __CPROVER_nondet_int();
    }
    l = __CPROVER_nondet_int();
    __CPROVER_assume(l >= 0 && l < n);
    r = __CPROVER_nondet_int();
    __CPROVER_assume(r >= 0 && r < n);
    __CPROVER_assume(l <= r);
    x = __CPROVER_nondet_int();

    int result = binarysearch2(arr, l, r, x);

    if (result != -1) {
        assert(arr[result] == x);
    }

    free(arr);
}