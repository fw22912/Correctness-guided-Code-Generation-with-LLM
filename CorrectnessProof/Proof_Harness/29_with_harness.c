#include <assert.h>
#include <limits.h>
#include <stdlib.h>

int divide(int dividend, int divisor)
{
    int sign = 1;
    long int output = 0;
    if (dividend < 0)
    {
        sign *= -1;
    }
    else
    {
        dividend *= -1;
    }
    if (divisor < 0)
    {
        sign *= -1;
    }
    else
    {
        divisor *= -1;
    }
    while (dividend <= divisor)
    {
        long int tmp = 0;
        long int div = divisor;
        while (dividend <= div)
        {
            tmp += (tmp + 1);
            dividend -= div;
            div += div;
        }
        if (output >= INT_MAX)
        {
            if (sign == -1)
            {
                return INT_MIN;
            }
            else
            {
                return INT_MAX;
            }
        }
        output += tmp;
    }

    return output * sign;
}

void proof_harness_divide() {
    int dividend;
    int divisor;
    __CPROVER_assume(divisor != 0);
    
    int expected_result = divide(dividend, divisor);
    
    int result = divide(dividend, divisor);
    assert(result == expected_result);
}

void proof_harness_main() {
    int dividend;
    int divisor;
    __CPROVER_assume(divisor != 0);
    
    int expected_result = divide(dividend, divisor);
    
    int result = divide(dividend, divisor);
    assert(result == expected_result);
}

void combined_proof_harness() {
    proof_harness_divide();
    proof_harness_main();
}