void proof_harness_factorial() {
    int x;
    __CPROVER_assume(x >= 0);
    __CPROVER_assume(x <= 20);  // Adjust the upper bound based on your needs
    
    long int expected_fac = 1;
    for (int i = 1; i <= x; i++) {
        expected_fac *= i;
    }

