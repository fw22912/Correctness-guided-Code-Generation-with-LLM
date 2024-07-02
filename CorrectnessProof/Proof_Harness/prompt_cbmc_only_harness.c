void proof_harness() {
    struct Account *source;
    struct Account *dest;
    unsigned short amount;
    source->bal = 0;
    dest->bal = 0;
    amount = 0;
    unsigned short initial_source_balance = source->bal;
    unsigned short initial_dest_balance = dest->bal;
    transfer(source, dest, amount);
    assert(source->bal == initial_source_balance - amount);
    assert(dest->bal == initial_dest_balance + amount);
}