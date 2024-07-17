void proof_harness_quaternion_multiply() {
    quaternion *in_quat1 = (quaternion *)malloc(sizeof(quaternion));
    __CPROVER_assume(in_quat1 != NULL);
    quaternion *in_quat2 = (quaternion *)malloc(sizeof(quaternion));
    __CPROVER_assume(in_quat2 != NULL);
    
    quaternion_multiply(in_quat1, in_quat2);
    free(in_quat1);
    free(in_quat2);
}

void proof_harness_quat_from_euler() {
    euler *in_euler = (euler *)malloc(sizeof(euler));
    __CPROVER_assume(in_euler != NULL);
    
    quat_from_euler(in_euler);
    free(in_euler);
}

void proof_harness_euler_from_quat() {
    quaternion *in_quat = (quaternion *)malloc(sizeof(quaternion));
    __CPROVER_assume(in_quat != NULL);
    
    euler_from_quat(in_quat);
    free(in_quat);
}

