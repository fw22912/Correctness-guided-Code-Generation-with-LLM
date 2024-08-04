
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    int N = 1000;

    for (int a = 1; a < 300; a++)
    {
        long tmp1 = N * N - 2 * a * N;
        long tmp2 = 2 * (N - a);
        div_t tmp3 = div(tmp1, tmp2);
        int b = tmp3.quot;
        int c = N - a - b;

        if (a * a + b * b == c * c)
        {
            printf("%d x %d x %d = %ld\n", a, b, c, (long int)a * b * c);
            return 0;
        }
    }

    return 0;
}