void proof_harness_calculate_next_xy() {
    int quotient;
    int prev[2];
    __CPROVER_assume(quotient >= -2147483648);
    __CPROVER_assume(quotient <= 2147483647);
    __CPROVER_assume(prev[0] >= -2147483648);
    __CPROVER_assume(prev[0] <= 2147483647);
    __CPROVER_assume(prev[1] >= -2147483648);
    __CPROVER_assume(prev[1] <= 2147483647);
    
    calculate_next_xy(quotient, prev);
    assert(prev[0] == prev[1] - (prev[0] * quotient));
}

void proof_harness_extended_euclidean_algorithm() {
    int a;
    int b;
    __CPROVER_assume(a >= -2147483648);
    __CPROVER_assume(a <= 2147483647);
    __CPROVER_assume(b >= -2147483648);
    __CPROVER_assume(b <= 2147483647);
    
    euclidean_result_t result = extended_euclidean_algorithm(a, b);
    
    int gcd = result.gcd;
    int x = result.x;
    int y = result.y;
    assert(a * x + b * y == gcd);
}

void proof_harness_single_test() {
    int a;
    int b;
    int gcd;
    int x;
    int y;
    __CPROVER_assume(a >= -2147483648);
    __CPROVER_assume(a <= 2147483647);
    __CPROVER_assume(b >= -2147483648);
    __CPROVER_assume(b <= 2147483647);
    __CPROVER_assume(gcd >= -2147483648);
    __CPROVER_assume(gcd <= 2147483647);
    __CPROVER_assume(x >= -2147483648);
    __CPROVER_assume(x <= 2147483647);
    __CPROVER_assume(y >= -2147483648);
    __CPROVER_assume(y <= 2147483647);
    
    single_test(a, b, gcd, x, y);
}

void proof_harness_xy_push() {
    int arr[2];
    int newval;
    __CPROVER_assume(newval >= -2147483648);
    __CPROVER_assume(newval <= 2147483647);
    
    xy_push(arr, newval);
    assert(arr[0] == newval);
}

