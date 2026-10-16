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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) {
            return "";
        }

        string output = "";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            size_t length = q.size();
            for (int i = 0; i < q.size(); ++i) {
                TreeNode* node = q.front();
                q.pop();
                if (node == nullptr) {
                    output += ",";
                    continue;
                }
                output += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            }
        }

        return output;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "") {
            return nullptr;
        }
        queue<string> serial;
        stringstream ss(data);
        string node;
        while (getline(ss, node, ',')) {
            serial.push(node);
        }

        string r = serial.front();
        serial.pop();
        // if (r == "") {
        //     return nullptr;
        // }

        TreeNode* root = new TreeNode(stoi(r));
        queue<TreeNode*> q;
        q.push(root);

        while (!serial.empty()) {
            size_t length = q.size();
            for (int i = 0; i < length; ++i) {
                TreeNode* node = q.front();
                q.pop();
                string left = serial.front();
                serial.pop();
                string right = serial.front();
                serial.pop();
                if (left != "") {
                    TreeNode* l = new TreeNode(stoi(left));
                    q.push(l);
                    node->left = l;
                }
                if (right != "") {
                    TreeNode* r = new TreeNode(stoi(right));
                    q.push(r);
                    node->right = r;
                }
            }
        }

        return root;
    }


};
