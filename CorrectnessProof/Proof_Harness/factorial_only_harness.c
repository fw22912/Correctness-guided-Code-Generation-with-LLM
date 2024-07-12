void proof_harness_main() {
    int a[200], n, counter, temp, i;
    a[0] = 1;
    counter = 0;
    __CPROVER_assume(n >= 0);
    __CPROVER_assume(n <= 2147483647);
    if (n < 0)
        printf("Cannot Calculate factorials for negative numbers.");
    else
    {
        for (; n >= 2; n--)
        {
            temp = 0;
            for (i = 0; i <= counter; i++)
            {
                temp = (a[i] * n) + temp;
                a[i] = temp % 10;
                temp = temp / 10;
            }

