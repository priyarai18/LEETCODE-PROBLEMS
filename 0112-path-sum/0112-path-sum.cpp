class Solution {
private:
    bool dfs(TreeNode* node, int currentSum, int targetSum) {
        if (node == nullptr) {
            return false;
        }

        currentSum += node->val;

        if (node->left == nullptr && node->right == nullptr) {
            return currentSum == targetSum;
        }

        return dfs(node->left, currentSum, targetSum) || 
               dfs(node->right, currentSum, targetSum);
    }

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root, 0, targetSum);
    }
};