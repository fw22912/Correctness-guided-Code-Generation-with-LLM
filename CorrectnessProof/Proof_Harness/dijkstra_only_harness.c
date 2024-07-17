void proof_harness_cf() {
    int a, b;
    __CPROVER_assume(a >= 0 && a <= MAX);
    __CPROVER_assume(b >= 0 && b <= MAX);
    int *x = &a;
    int *y = &b;
    assert(cf(x, y) == b - a);
}

void proof_harness_enqueue() {
    int v;
    __CPROVER_assume(qp < MAX);
    __CPROVER_assume(v >= 0 && v <= MAX);
    enqueue(v);
    assert(q[qp-1] == v);
}

void proof_harness_dijkstra() {
    int s;
    __CPROVER_assume(s >= 0 && s < V);
    __CPROVER_assume(V >= 1 && V <= MAX);
    dijkstra(s);
    assert(dist[s] == 0);
    for (int i = 0; i < V; i++) {
        if (i != s) {
            assert(dist[i] >= 0);
        }

void proof_harness_queue_has_something() {
    qp = 0;
    assert(!queue_has_something());
    qp = 1;
    assert(queue_has_something());
}

void proof_harness_dequeue() {
    int i, v;
    for (i = 0; i < MAX; i++) {
        q[i] = i;
    }

