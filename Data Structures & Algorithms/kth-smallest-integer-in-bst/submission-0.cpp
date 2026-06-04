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
    std::vector<int> visited;
    int k {0};

public:
    void inorder(TreeNode* node) {
        if (not node || visited.size() >= k) {
            return;
        }

        inorder(node->left);
        visited.push_back(node->val);
        inorder(node->right);
    }

    int kthSmallest(TreeNode* root, int k) {
        this->k = k; // early termination
        inorder(root);
        return visited[k-1];
    }
};
