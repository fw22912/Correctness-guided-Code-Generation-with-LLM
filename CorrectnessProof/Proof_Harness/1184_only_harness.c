void combined_proof_harness() {
    proof_harness_distanceBetweenBusStops();
    proof_harness_main();
}

void proof_harness_main() {
    int distanceSize;
    __CPROVER_assume(distanceSize >= 0);
    int *distance = (int *)malloc(sizeof(int) * distanceSize);
    __CPROVER_assume(distance != NULL);

    int start;
    __CPROVER_assume(start >= 0);
    __CPROVER_assume(start < distanceSize);

    int destination;
    __CPROVER_assume(destination >= 0);
    __CPROVER_assume(destination < distanceSize);

    for (int i = 0; i < distanceSize; ++i) {
        distance[i] = rand();
    }

void proof_harness_distanceBetweenBusStops() {
    int distanceSize;
    __CPROVER_assume(distanceSize >= 0);
    int *distance = (int *)malloc(sizeof(int) * distanceSize);
    __CPROVER_assume(distance != NULL);

    int start;
    __CPROVER_assume(start >= 0);
    __CPROVER_assume(start < distanceSize);

    int destination;
    __CPROVER_assume(destination >= 0);
    __CPROVER_assume(destination < distanceSize);

    for (int i = 0; i < distanceSize; ++i) {
        distance[i] = rand();
    }

