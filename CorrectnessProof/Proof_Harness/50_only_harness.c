void combined_proof_harness(){
    proof_harness_powPositive();
    proof_harness_myPow();
    proof_harness_main();
}

void proof_harness_myPow(){
    double x;
    int n;
    __CPROVER_assume(x != 0);
    double result = myPow(x, n);
    assert(result == pow(x, n));
}

void proof_harness_main(){
    double x;
    int n;
    __CPROVER_assume(x != 0);
    double result = myPow(x, n);
    assert(result == pow(x, n));
}

void proof_harness_powPositive(){
    double x;
    int n;
    __CPROVER_assume(n >= 1);
    __CPROVER_assume(x != 0);
    double result = powPositive(x, n);
    assert(result == pow(x, n));
}

