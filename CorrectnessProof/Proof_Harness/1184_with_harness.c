#include <assert.h>
#include <stdlib.h>

int distanceBetweenBusStops(int *distance, int distanceSize, int start,
                            int destination)
{
    int sum1 = 0, sum2 = 0;
    if (start > destination)
    {
        int tmp = start;
        start = destination;
        destination = tmp;
    }
    for (auto i = 0; i < distanceSize; ++i)
    {
        if (i >= start && i < destination)
            sum1 += distance[i];
        else
            sum2 += distance[i];
    }
    return sum1 < sum2 ? sum1 : sum2;
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

    int expected_result = distanceBetweenBusStops(distance, distanceSize, start, destination);
    int actual_result = distanceBetweenBusStops(distance, distanceSize, start, destination);
    assert(expected_result == actual_result);

    free(distance);
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

    int result = distanceBetweenBusStops(distance, distanceSize, start, destination);

    free(distance);
}

void combined_proof_harness() {
    proof_harness_distanceBetweenBusStops();
    proof_harness_main();
}