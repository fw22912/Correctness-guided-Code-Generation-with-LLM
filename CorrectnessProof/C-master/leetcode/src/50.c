double powPositive(double x, int n){
    if (n == 1){
        return x;
    }

    double val = powPositive(x, n / 2);
    double result = val * val;
    
    
    if (n & 1 > 0){
        result *= x;
    }

    return result;
}




double myPow(double x, int n){
    if (n == 0){
        return 1;
    }

    const int LOWER_BOUND = -2147483648;

    
    
    if (n == LOWER_BOUND){
        return 1 / (powPositive(x, -(n + 1)) * x);
    }

    
    if (n < 0){
        return 1 / powPositive(x, -n);
    }

    return powPositive(x, n);
}
