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
    struct hash_pair {
        template<class T1, class T2>
        size_t operator()(const pair<T1,T2>& p) const {
            size_t hash1 = hash<T1>{}(p.first);
            size_t hash2 = hash<T2>{}(p.second);
            return hash1 ^ (hash2 + 17);
        }
    };

    int rob(TreeNode* root) {
        unordered_map<pair<TreeNode*, bool>, int, hash_pair> visited;
        return dfs(root, true, visited);
    }

    int dfs(TreeNode* node, bool canRob,
            unordered_map<pair<TreeNode*, bool>, int, hash_pair>& visited) {
        if (node == nullptr) {
            return 0;
        }
        if (visited.contains({node, canRob})) {
            return visited[{node, canRob}];
        }
        int rob{0};
        if (canRob) {
            rob = node->val + dfs(node->left, false, visited) + dfs(node->right, false, visited);
        }
        int skip = dfs(node->left, true, visited) + dfs(node->right, true, visited);

        visited[{node, canRob}] = max(rob, skip);
        return visited[{node, canRob}];
    }
};