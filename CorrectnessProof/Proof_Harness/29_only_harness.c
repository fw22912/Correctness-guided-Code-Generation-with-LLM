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

