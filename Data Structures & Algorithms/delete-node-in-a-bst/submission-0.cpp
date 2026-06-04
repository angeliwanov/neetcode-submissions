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
    int findMax (TreeNode* root) {
        while (root->right != nullptr) {
            root = root->right;
        }
        return root->val;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {  
        if (!root) return nullptr;

        if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else if (root->val == key) {
            if (!root->left) {
                return root->right;
            } else if (!root->right) {
                return root->left;
            }
            root->val = findMax(root->left);
            root->left = deleteNode(root->left, root->val);
        }

        return root;
    }
};