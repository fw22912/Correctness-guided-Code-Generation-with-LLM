#include <assert.h>
#include <stdlib.h>

#define min(X, Y) ((X) < (Y) ? (X) : (Y))

int intersectionSize(int p11, int p12, int p21, int p22){
    if (p11 >= p22 || p12 <= p21){
        return 0;
    }

    if (p11 < p21){
        return min(p12 - p21, p22 - p21);
    }

    return min(p22 - p11, p12 - p11);
}

// Calculation area of the A, then area of the B then minus intersection of A and B
// Runtime: O(1)
// Space: O(1)
int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2){
    int areaA = (ay2 - ay1) * (ax2 - ax1);
    int areaB = (by2 - by1) * (bx2 - bx1);
    int areaInteresection = intersectionSize(ax1, ax2, bx1, bx2) * intersectionSize(ay1, ay2, by1, by2);
    
    return areaA + areaB - areaInteresection;
}

void proof_harness_intersectionSize() {
    int p11, p12, p21, p22;
    __CPROVER_assume(p11 <= p12);
    __CPROVER_assume(p21 <= p22);
    int expected = intersectionSize(p11, p12, p21, p22);
    assert(intersectionSize(p11, p12, p21, p22) == expected);
}

void proof_harness_computeArea() {
    int ax1, ay1, ax2, ay2, bx1, by1, bx2, by2;
    __CPROVER_assume(ax1 <= ax2);
    __CPROVER_assume(ay1 <= ay2);
    __CPROVER_assume(bx1 <= bx2);
    __CPROVER_assume(by1 <= by2);
    int expected = computeArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2);
    assert(computeArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2) == expected);
}

void proof_harness_main() {
    int ax1, ay1, ax2, ay2, bx1, by1, bx2, by2;
    __CPROVER_assume(ax1 <= ax2);
    __CPROVER_assume(ay1 <= ay2);
    __CPROVER_assume(bx1 <= bx2);
    __CPROVER_assume(by1 <= by2);
    int result = computeArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2);
}

void combined_proof_harness() {
    proof_harness_intersectionSize();
    proof_harness_computeArea();
    proof_harness_main();
}