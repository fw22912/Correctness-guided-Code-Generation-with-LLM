#include <assert.h>
#include <stdlib.h>

void swap(int *x, int *y){
    if (x==y)
        return;
   *x = *x + *y;
    *y= *x - *y;
    *x= *x - *y;
}

void sortColors(int* arr, int n){
    int start=0, mid=0, end=n-1;
    while(mid<=end){
        if(arr[mid]==1)
            mid++;
        else if(arr[mid]==0){
            swap(&arr[mid],&arr[start]);
            mid++;
            start++;
        }
        else{
            swap(&arr[mid],&arr[end]);
            end--;
        }
    }
}

void proof_harness_swap() {
    int *x = (int *)malloc(sizeof(int));
    __CPROVER_assume(x != NULL);
    int *y = (int *)malloc(sizeof(int));
    __CPROVER_assume(y != NULL);
    int initial_x = *x;
    int initial_y = *y;
    swap(x, y);
    if (x == y) {
        assert(*x == initial_x);
        assert(*y == initial_y);
    } else {
        assert(*x == initial_y);
        assert(*y == initial_x);
    }
    free(x);
    free(y);
}

void proof_harness_sortColors() {
    int n;
    __CPROVER_assume(n >= 0);
    int *arr = (int *)malloc(sizeof(int) * n);
    __CPROVER_assume(arr != NULL);
    for (int i = 0; i < n; i++) {
        __CPROVER_assume(arr[i] >= 0 && arr[i] <= 2);
    }
    sortColors(arr, n);
    int last_color = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] < last_color) {
            assert(0);
        }
        last_color = arr[i];
    }
    free(arr);
}

void combined_proof_harness() {
    proof_harness_swap();
    proof_harness_sortColors();
}

int main() {
    combined_proof_harness();
    return 0;
}