void proof_harness_bSTIteratorCreate() {
    struct TreeNode *root = NULL; // Create a NULL root for testing
    BSTIterator *obj = bSTIteratorCreate(root);
    assert(obj != NULL); 
    assert(obj->values != NULL); 
    assert(obj->NumberOfNodes == 0);
    assert(obj->CurrentIndex == 0);
    assert(obj->values[0] == INT_MAX); 
    bSTIteratorFree(obj); 
}

void proof_harness_bSTIteratorHasNext() {
    struct TreeNode *root = NULL; // Create a NULL root for testing
    BSTIterator *obj = bSTIteratorCreate(root);
    bool hasNext = bSTIteratorHasNext(obj);
    assert(hasNext == false); 
    bSTIteratorFree(obj); 
}

void combined_proof_harness() {
    proof_harness_bSTIteratorCreate();
    proof_harness_bSTIteratorNext();
    proof_harness_bSTIteratorHasNext();
    proof_harness_bSTIteratorFree();
}

void proof_harness_bSTIteratorNext() {
    struct TreeNode *root = NULL; // Create a NULL root for testing
    BSTIterator *obj = bSTIteratorCreate(root);
    int NextValue = bSTIteratorNext(obj);
    assert(NextValue == INT_MAX); 
    bSTIteratorFree(obj);
}

void proof_harness_bSTIteratorFree() {
    struct TreeNode *root = NULL; // Create a NULL root for testing
    BSTIterator *obj = bSTIteratorCreate(root);
    bSTIteratorFree(obj);
    // After freeing, we can't access obj anymore. So, we can't use assert here
}

