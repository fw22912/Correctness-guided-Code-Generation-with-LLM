void proof_harness() { 
        struct node *source;
        struct node *dest;
        int amount;
        CPROVER_assume(source != NULL);
        CPROVER_assume(dest != NULL);
        CPROVER_assume(amount >= 0);
        CPROVER_assume(source->data >= 0);
        CPROVER_assume(dest->data >= 0);

        int initial_source_data = source->data;
        int initial_dest_data = dest->data;

        transfer(source, dest, amount);

        assert(source->data == initial_source_data - amount);
        assert(dest->data == initial_dest_data + amount);
    }