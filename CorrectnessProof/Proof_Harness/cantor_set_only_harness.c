void proof_harness_propagate() {
    CantorSet *head = (CantorSet *)malloc(sizeof(CantorSet));
    __CPROVER_assume(head != NULL);
    head->next = (CantorSet *)malloc(sizeof(CantorSet));
    __CPROVER_assume(head->next != NULL);
    head->next->next = (CantorSet *)malloc(sizeof(CantorSet));
    __CPROVER_assume(head->next->next != NULL);
    head->next->next->next = NULL;
    
    head->start = 0.0;
    head->end = 1.0;
    head->next->start = 0.0;
    head->next->end = 1.0;
    head->next->next->start = 0.0;
    head->next->next->end = 1.0;
    
    propagate(head);
    assert(head->start == 0.0);
    assert(head->end == 1.0/3.0);
    assert(head->next->start == 1.0/3.0);
    assert(head->next->end == 2.0/3.0);
    assert(head->next->next->start == 2.0/3.0);
    assert(head->next->next->end == 1.0);
    
    free(head->next->next);
    free(head->next);
    free(head);
}

void proof_harness_free_memory() {
    CantorSet *head = (CantorSet *)malloc(sizeof(CantorSet));
    __CPROVER_assume(head != NULL);
    head->next = (CantorSet *)malloc(sizeof(CantorSet));
    __CPROVER_assume(head->next != NULL);
    head->next->next = (CantorSet *)malloc(sizeof(CantorSet));
    __CPROVER_assume(head->next->next != NULL);
    head->next->next->next = NULL;
    
    head->start = 0.0;
    head->end = 1.0;
    head->next->start = 0.0;
    head->next->end = 1.0;
    head->next->next->start = 0.0;
    head->next->next->end = 1.0;
    
    free_memory(head);
}

void proof_harness_print() {
    CantorSet *head = (CantorSet *)malloc(sizeof(CantorSet));
    __CPROVER_assume(head != NULL);
    head->next = (CantorSet *)malloc(sizeof(CantorSet));
    __CPROVER_assume(head->next != NULL);
    head->next->next = NULL;
    
    head->start = 0.0;
    head->end = 1.0;
    head->next->start = 0.0;
    head->next->end = 1.0;
    
    print(head);
    
    free(head->next);
    free(head);
}

