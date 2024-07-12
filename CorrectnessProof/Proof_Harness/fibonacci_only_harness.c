void proof_harness_fib() {
    int number;
    __CPROVER_assume(number >= 1);
    __CPROVER_assume(number <= 48);
    unsigned int result = fib(number);
    if (number == 1) {
        assert(result == 0);
    }

void proof_harness_getInput() {
    int num = getInput();
    assert(num >= 1);
    assert(num <= 48);
}

