

#define max(a,b) (((a)>(b))?(a):(b))

int recursiveSolve(struct TreeNode* node, int* result){
    if (node == NULL){
        return 0;
    }

    int leftSum = max(recursiveSolve(node->left, result), 0);
    int rightSum = max(recursiveSolve(node->right, result), 0);

    
    int maxValueNode = node->val + leftSum + rightSum;
    *result = max(maxValueNode, *result);

    
    return node->val + max(leftSum, rightSum);
}




int maxPathSum(struct TreeNode* root){
    const int LOWER_BOUND = -2147483648
    int result = LOWER_BOUND;
    recursiveSolve(root, &result);
    return result;
}
