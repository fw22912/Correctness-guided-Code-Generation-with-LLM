void proof_harness_main() {
    int x;
    __CPROVER_assume(x >= 0);
    mySqrt(x);
}

void proof_harness_mySqrt() {
    int x;
    __CPROVER_assume(x >= 0);
    int result = mySqrt(x);
    long long int sq = (long long int)result * (long long int)result;
    if (sq <= x) {
        assert(sq <= x && x < (result + 1) * (result + 1));
    }

void combined_proof_harness() {
    proof_harness_mySqrt();
    proof_harness_main();
}

