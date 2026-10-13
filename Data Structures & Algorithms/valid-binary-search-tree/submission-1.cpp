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
    bool isValidBST(TreeNode* root) {
        vector<int> nodeValues;
        inorder(root, nodeValues);
        
        for (size_t i = 1; i < nodeValues.size(); ++i) {
            if (nodeValues[i] <= nodeValues[i-1]) {
                return false;
            }
        }

        return true;
    }

    void inorder(TreeNode* node, vector<int>& nodeValues) {
        if (node == nullptr) {
            return;
        }
        inorder(node->left, nodeValues);
        nodeValues.emplace_back(node->val);
        inorder(node->right, nodeValues);
    }
};
