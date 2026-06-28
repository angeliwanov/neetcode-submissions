class TrieNode {
public:
    std::unordered_map<char, std::unique_ptr<TrieNode>> children;
    bool isEnd{false};        
};

class PrefixTree {
private:
    std::unique_ptr<TrieNode> root;
public:
    PrefixTree() {
        root = std::make_unique<TrieNode>();
    }
    
    void insert(string word) {
        TrieNode* curr = root.get();
        for (auto ch : word) {
            if (curr->children.find(ch) == curr->children.end()) {
                curr->children[ch] = std::make_unique<TrieNode>();
            }
            curr = curr->children[ch].get();
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root.get();
        for (auto ch: word) {
            if (curr->children.find(ch) == curr->children.end()) {
                return false;
            }
            curr = curr->children[ch].get();
        }
        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root.get();
        for (auto ch: prefix) {
            if (curr->children.find(ch) == curr->children.end()) {
                return false;
            }
            curr = curr->children[ch].get();
        }
        return true;
    }
};
