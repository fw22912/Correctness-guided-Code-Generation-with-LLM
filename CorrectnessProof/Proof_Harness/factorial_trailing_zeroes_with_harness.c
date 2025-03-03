/*
programme for computing number of zeroes at the end of factorial of a given
number n
*/
#include <math.h>  //including math.h header file to use pow function
#include <stdio.h>
#include <assert.h>
int main()
{
    int i, n, test = 0, count = 0;
    // taking input number n
    scanf("%d", &n);

    // looping from 1 till loop break
    for (i = 1;; i++)
    {
        test =
            n /
            pow(5,
                i);  // division of n by ith power of 5(storing in integer form)
        if (test !=
            0)  // condition for zeroes at end corresponding individual ith case
        {
            count = count + test;
        }
        else
            break;  // break the loop for if test=0
    }
    printf("%d\n", count);
    return 0;
}

void proof_harness_main() {
    int n;
    __CPROVER_assume(n >= 0);
    __CPROVER_assume(n <= 2147483647);
    int i, test = 0, count = 0;
    for (i = 1;; i++) {
        test = n / pow(5, i);
        if (test != 0) {
            count = count + test;
        } else
            break;
    }
}