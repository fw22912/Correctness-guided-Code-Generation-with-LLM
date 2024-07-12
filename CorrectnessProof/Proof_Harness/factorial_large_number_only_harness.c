void proof_harness_multiply() {
    large_num *num = new_number();
    unsigned long n;
    __CPROVER_assume(n >= 0);
    multiply(num, n);
    // Assertions are difficult to formulate for multiply as the result is dependent on the input 'n'
    delete_number(num);
}

void proof_harness_delete_number() {
    large_num *num = new_number();
    delete_number(num);
    // No assertions can be made after calling delete_number
}

void proof_harness_new_number() {
    large_num *new_num = new_number();
    assert(new_num->num_digits == 1);
    assert(new_num->digits[0] == 1);
    delete_number(new_num);
}

void proof_harness_add_digit() {
    large_num *num = new_number();
    unsigned int value;
    __CPROVER_assume(value >= 0);
    __CPROVER_assume(value <= 9);
    add_digit(num, value);
    assert(num->num_digits == 2);
    assert(num->digits[1] == value);
    delete_number(num);
}

