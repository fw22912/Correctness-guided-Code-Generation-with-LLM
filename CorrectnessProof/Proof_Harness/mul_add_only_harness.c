void proof_harness_multiply() {
    int a;
    int b;
    int result;

    a = rand();
    b = rand();
    result = multiply(a, b);
    assert(result == a * b);
}

void proof_harness_add() {
    int a;
    int b;
    int result;

    a = rand();
    b = rand();
    result = add(a, b);
    assert(result == a + b);
}

