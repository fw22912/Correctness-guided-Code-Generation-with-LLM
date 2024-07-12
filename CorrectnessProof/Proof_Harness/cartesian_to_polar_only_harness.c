void proof_harness_to_polar() {
    double x, y, r, theta;
    __CPROVER_assume(x >= -2147483648);
    __CPROVER_assume(x <= 2147483647);
    __CPROVER_assume(y >= -2147483648);
    __CPROVER_assume(y <= 2147483647);
    to_polar(x, y, &r, &theta);
}

