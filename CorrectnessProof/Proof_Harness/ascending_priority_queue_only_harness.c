void proof_harness_createqueue() {
    createqueue();
    assert(front == NULL);
    assert(rear == NULL);
}

void proof_harness_insert() {
    createqueue();
    insert(1);
    assert(front->data == 1);
    assert(rear->data == 1);
    assert(front->next == NULL);
    insert(2);
    assert(front->data == 1);
    assert(rear->data == 2);
    assert(front->next->data == 2);
    assert(front->next->next == NULL);
}

void proof_harness_removes() {
    createqueue();
    insert(1);
    assert(removes() == 1);
    assert(front == NULL);
    assert(rear == NULL);
    insert(1);
    insert(2);
    assert(removes() == 1);
    assert(front->data == 2);
    assert(rear->data == 2);
    assert(front->next == NULL);
    insert(3);
    assert(removes() == 2);
    assert(front->data == 3);
    assert(rear->data == 3);
    assert(front->next == NULL);
}

void proof_harness_empty() {
    createqueue();
    assert(empty() == 1);
    insert(1);
    assert(empty() == 0);
}

void proof_harness_show() {
    createqueue();
    show();
    insert(1);
    show();
}

void proof_harness_destroyqueue() {
    createqueue();
    destroyqueue();
    assert(front == NULL);
    assert(rear == NULL);
}

