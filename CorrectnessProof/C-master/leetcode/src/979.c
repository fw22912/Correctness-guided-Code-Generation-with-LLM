

struct NodeDistributeInfo {
    int distributeMoves;
    int distributeExcess;
};

struct NodeDistributeInfo* getDisturb(struct TreeNode* node) {
    struct NodeDistributeInfo* result = malloc(sizeof(struct NodeDistributeInfo));

    if (node == NULL) {
        result->distributeMoves = 0;
        result->distributeExcess = 1;
        return result;
    }

    struct NodeDistributeInfo* leftDistribute = getDisturb(node->left);
    struct NodeDistributeInfo* rightDistribute = getDisturb(node->right);

    int coinsToLeft = 1 - leftDistribute->distributeExcess;
    int coinsToRight = 1 - rightDistribute->distributeExcess;

    
    result->distributeMoves = leftDistribute->distributeMoves + rightDistribute->distributeMoves + abs(coinsToLeft) + abs(coinsToRight);
    result->distributeExcess = node->val - coinsToLeft - coinsToRight;

    free(leftDistribute);
    free(rightDistribute);

    return result;
}






int distributeCoins(struct TreeNode* root) {
    return getDisturb(root)->distributeMoves;
}
