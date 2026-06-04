/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    std::vector<int> dfs(TreeNode* node) {
        if (not node) {
            return {1, 0};
        }

        std::vector<int> left = dfs(node->left);
        std::vector<int> right = dfs(node->right);
        int balanced = left[0] && right[0] && std::abs(left[1] - right[1]) <= 1;
        int height = std::max(left[1], right[1]) + 1;

        return {balanced, height};
    }

    bool isBalanced(TreeNode* root) {
        return dfs(root)[0];        
    }
};
