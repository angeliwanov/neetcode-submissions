/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> visited;
        return dfs(head, visited);
    }

    Node* dfs(Node* node, unordered_map<Node*, Node*>& visited) {
        if (!node) {
            return nullptr;
        }
        if (visited.contains(node)) {
            return visited[node];
        }
        
        Node* copy = new Node(node->val);
        visited[node] = copy;
        copy->next = dfs(node->next, visited);
        copy->random = dfs(node->random, visited);
        return copy;
    }
};
