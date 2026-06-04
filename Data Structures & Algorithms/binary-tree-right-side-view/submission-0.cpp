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
    vector<int> rightSideView(TreeNode* root) {
        std::vector<int> result;
        if (root == nullptr) {
            return result;            
        }
        std::queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            result.push_back(que.back()->val);

            size_t q_len = que.size();
            for (size_t i = 0; i < q_len; ++i) {
                TreeNode* node = que.front();
                que.pop();
                
                if (node->left) {
                    que.push(node->left);
                }
                if (node->right) {
                    que.push(node->right);
                }
            }
        }

        return result;
    }
};
