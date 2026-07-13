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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> res;

        while (root != nullptr || !stk.empty()) {
            if (root != nullptr) {
                res.push_back(root->val);
                stk.push(root->left);
                root = root->right;
            } else {
                root = stk.top();
                stk.pop();
            }
        }

        std::ranges::reverse(res);
        return res;
    }
};