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
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }
        std::vector<int> level;
        std::queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            level.clear();
            size_t q_len = q.size();
            for (size_t i = 0; i < q_len; ++i) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);

                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            result.push_back(level);
        }

        return result;
    }
};
