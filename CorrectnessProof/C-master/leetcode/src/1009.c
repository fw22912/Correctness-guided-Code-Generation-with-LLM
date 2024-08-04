






int bitwiseComplement(int n){
    if (n == 0){
        return 1;
    }

    int binary_number_length = ceil(log2(n));
    return (~n) & ((1 << binary_number_length) - 1);
}
