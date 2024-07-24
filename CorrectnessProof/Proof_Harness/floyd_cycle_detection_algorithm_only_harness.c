void proof_harness_main() {
        test();
    }

void combined_proof_harness() {
        proof_harness_duplicateNumber();
        proof_harness_test();
        proof_harness_main();
    }

void proof_harness_test() {
        uint32_t arr[] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610}

void proof_harness_duplicateNumber() {
        uint32_t *in_arr;
        size_t n;
        
        in_arr = (uint32_t *)malloc(sizeof(uint32_t) * (n + 1));
        if (in_arr == NULL) {
            return;
        }

