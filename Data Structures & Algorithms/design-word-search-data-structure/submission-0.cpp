class TrieNode {
   public:
    std::unordered_map<char, std::unique_ptr<TrieNode>> children;
    bool isEnd{false};
};

class WordDictionary {
   private:
    std::unique_ptr<TrieNode> root;

   public:
    WordDictionary() { root = std::make_unique<TrieNode>(); }

    void addWord(string word) {
        TrieNode* curr = root.get();
        for (auto ch : word) {
            if (!curr->children.contains(ch)) {
                curr->children[ch] = std::make_unique<TrieNode>();
            }
            curr = curr->children[ch].get();
        }
        curr->isEnd = true;
    }

    bool search(string word) { return dfs(root.get(), word, 0); }

    bool dfs(TrieNode* curr, string word, size_t index) {
        for (size_t i = index; i < word.size(); i++) {
            auto ch = word[i];
            if (ch == '.') {                
                for (auto& [ch, child] : curr->children) {
                    if (dfs(child.get(), word, i+1)) {
                        return true;
                    }
                }
                return false;
            } else if (!curr->children.contains(ch)) {
                return false;
            }
            curr = curr->children[ch].get();
        }
        return curr->isEnd;
    }
};
