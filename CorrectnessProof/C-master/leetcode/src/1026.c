

#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))

void recursiveSolve(struct TreeNode* node, int* result, int minVal, int maxVal){
    if (node == NULL){
        return;
    }

    *result = max(*result, abs(minVal - node->val));
    *result = max(*result, abs(maxVal - node->val));

    minVal = min(minVal, node->val);
    maxVal = max(maxVal, node->val);

    recursiveSolve(node->left, result, minVal, maxVal);
    recursiveSolve(node->right, result, minVal, maxVal);
}





int maxAncestorDiff(struct TreeNode* root){
    int result = 0;
    int maxVal = root->val;
    int minVal = root->val;
    recursiveSolve(root, &result, minVal, maxVal);
    return result;
}
