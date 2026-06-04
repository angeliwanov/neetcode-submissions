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
private:
    bool backtrack(TreeNode* node, int remain) {
        if (node == nullptr) {
            return false;
        }

        if (node->left == nullptr && node->right == nullptr) {
            return remain == node->val;
        }

        return backtrack(node->left, remain - node->val) || backtrack(node->right, remain - node->val);

    }

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return backtrack(root, targetSum);
    }
};