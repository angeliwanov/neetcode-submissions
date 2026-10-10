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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter{0};
        dfs(root, diameter);
        return diameter;
    }

    int dfs(TreeNode* node, int& diameter) {
        if (node == nullptr) {
            return 0;
        }

        int left = node->left ? 1 + dfs(node->left, diameter) : 0;
        int right = node->right ? 1 + dfs(node->right, diameter) : 0;

        diameter = max(diameter, left + right);
        return max(left, right);
    }
};
