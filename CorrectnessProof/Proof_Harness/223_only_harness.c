void proof_harness_computeArea() {
    int ax1, ay1, ax2, ay2, bx1, by1, bx2, by2;
    __CPROVER_assume(ax1 <= ax2);
    __CPROVER_assume(ay1 <= ay2);
    __CPROVER_assume(bx1 <= bx2);
    __CPROVER_assume(by1 <= by2);
    int expected = computeArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2);
    assert(computeArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2) == expected);
}

void combined_proof_harness() {
    proof_harness_intersectionSize();
    proof_harness_computeArea();
    proof_harness_main();
}

void proof_harness_intersectionSize() {
    int p11, p12, p21, p22;
    __CPROVER_assume(p11 <= p12);
    __CPROVER_assume(p21 <= p22);
    int expected = intersectionSize(p11, p12, p21, p22);
    assert(intersectionSize(p11, p12, p21, p22) == expected);
}

void proof_harness_main() {
    int ax1, ay1, ax2, ay2, bx1, by1, bx2, by2;
    __CPROVER_assume(ax1 <= ax2);
    __CPROVER_assume(ay1 <= ay2);
    __CPROVER_assume(bx1 <= bx2);
    __CPROVER_assume(by1 <= by2);
    int result = computeArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2);
}

