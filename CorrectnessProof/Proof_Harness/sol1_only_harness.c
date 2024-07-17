void proof_harness_main() {
    int maxNumber = 0;
    int n = 0;
    int n1;
    __CPROVER_assume(n >= 0);
    if (isprime(n) == 1) {
        assert(n == n);
    }

void proof_harness_isprime() {
    int no;
    __CPROVER_assume(no >= 0);
    char result = isprime(no);
    if (no == 2) {
        assert(result == 1);
    }

