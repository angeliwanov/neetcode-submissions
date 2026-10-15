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
    int maxPathSum(TreeNode* root) {
        int pathSum{-1000};
        return max(dfs(root, pathSum), pathSum);
    }

    int dfs(TreeNode* node, int& pathSum) {
        if (node == nullptr) {
            return -1000;
        }

        int left {dfs(node->left, pathSum)};
        int right {dfs(node->right, pathSum)};

        int skip {max(left, right)};
        skip = max(skip, node->val + left + right);
        pathSum = max(pathSum, skip);

        int take = max(node->val + left, node->val + right);
        return max(node->val, take);
    }
};
