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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr and subRoot == nullptr) {
            return true;
        }
        if (root == nullptr or subRoot == nullptr) {
            return false;
        }

        return isSameTree(root, subRoot) or isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr and q == nullptr) {
            return true;
        }
        if (p == nullptr or q == nullptr) {
            return false;
        }

        return p->val == q->val and isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
    }
};
