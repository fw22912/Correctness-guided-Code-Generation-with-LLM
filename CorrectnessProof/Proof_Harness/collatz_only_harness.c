void proof_harness_main() {
    unsigned long long n, curr_no, num_steps = 0;
    __CPROVER_assume(n >= 0);
    __CPROVER_assume(n <= 18446744073709551615);
    curr_no = n;
    while (curr_no != 1) {
        num_steps++;
        if (curr_no % 2 == 0) {
            curr_no = curr_no / 2;
        }

