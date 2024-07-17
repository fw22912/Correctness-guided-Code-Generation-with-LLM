#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX 20
#define INF 999

int mat[MAX][MAX];
int V;

int dist[MAX];

int q[MAX];
int qp = 0;

void enqueue(int v) { q[qp++] = v; }

int cf(void *a, void *b)
{
    int *x = (int *)a;
    int *y = (int *)b;
    return *y - *x;
}

int dequeue()
{
    qsort(q, qp, sizeof(int), cf);
    return q[--qp];
}

int queue_has_something() { return (qp > 0); }

int visited[MAX];
int vp = 0;

void dijkstra(int s)
{
    dist[s] = 0;
    int i;
    for (i = 0; i < V; ++i)
    {
        if (i != s)
        {
            dist[i] = INF;
        }
        enqueue(i);
    }
    while (queue_has_something())
    {
        int u = dequeue();
        visited[vp++] = u;
        for (i = 0; i < V; ++i)
        {
            if (mat[u][i])
            {
                if (dist[i] > dist[u] + mat[u][i])
                {
                    dist[i] = dist[u] + mat[u][i];
                }
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    printf("Enter the number of vertices: ");
    scanf(" %d", &V);
    printf("Enter the adj matrix: ");
    int i, j;
    for (i = 0; i < V; ++i)
    {
        for (j = 0; j < V; ++j)
        {
            scanf(" %d", &mat[i][j]);
        }
    }

    dijkstra(0);

    printf("\nNode\tDist\n");
    for (i = 0; i < V; ++i)
    {
        printf("%d\t%d\n", i, dist[i]);
    }

    return 0;
}

void proof_harness_enqueue() {
    int v;
    __CPROVER_assume(qp < MAX);
    __CPROVER_assume(v >= 0 && v <= MAX);
    enqueue(v);
    assert(q[qp-1] == v);
}

void proof_harness_cf() {
    int a, b;
    __CPROVER_assume(a >= 0 && a <= MAX);
    __CPROVER_assume(b >= 0 && b <= MAX);
    int *x = &a;
    int *y = &b;
    assert(cf(x, y) == b - a);
}

void proof_harness_dequeue() {
    int i, v;
    for (i = 0; i < MAX; i++) {
        q[i] = i;
    }
    qp = MAX;
    v = dequeue();
    assert(v == 0);
}

void proof_harness_queue_has_something() {
    qp = 0;
    assert(!queue_has_something());
    qp = 1;
    assert(queue_has_something());
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
    }
}