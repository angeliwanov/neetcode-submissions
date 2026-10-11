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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return nullptr;
        }
        bool left {dfs(root->left, p, q)};
        bool right {dfs(root->right, p, q)};
        bool curr {root == p || root == q};

        if ((curr && left) || (curr && right) || (left && right)) {
            return root;
        }
        return lowestCommonAncestor(root->left, p, q) ? lowestCommonAncestor(root->left, p, q): lowestCommonAncestor(root->right, p, q);
    }

    bool dfs(TreeNode* node, TreeNode* p, TreeNode* q) {
        if (node == nullptr) {
            return false;
        }
        if (node == p or node == q) {
            return true;
        }
        return dfs(node->left, p, q) || dfs(node->right, p, q);
    }
};
