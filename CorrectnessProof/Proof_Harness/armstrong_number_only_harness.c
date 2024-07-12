void proof_harness_order() {
        int x;
        __CPROVER_assume(x >= 0);
        __CPROVER_assume(x <= 2147483647);
        
        int result = order(x);
        // Assertion to check the result 
        // ... Add your assertion here if required
    }

void proof_harness_isArmstrong() {
        int x;
        __CPROVER_assume(x >= 0);
        __CPROVER_assume(x <= 2147483647);
        
        int result = isArmstrong(x);
        // Assertion to check the result 
        // ... Add your assertion here if required
    }

void proof_harness_power() {
        int x;
        unsigned int y;
        __CPROVER_assume(x >= 0);
        __CPROVER_assume(x <= 2147483647);
        __CPROVER_assume(y >= 0);
        __CPROVER_assume(y <= 2147483647);
        
        int result = power(x, y);
        // Assertion to check the result 
        // ... Add your assertion here if required
    }

