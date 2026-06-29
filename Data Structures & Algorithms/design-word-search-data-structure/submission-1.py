class TrieNode:
    def __init__(self):
        self.children = {}
        self.end = False

class WordDictionary:

    def __init__(self):
        self.root = TrieNode()

    def addWord(self, word: str) -> None:
        curr = self.root
        for ch in word:
            if ch not in curr.children:
                curr.children[ch] = TrieNode()
            curr = curr.children[ch]
        curr.end = True

    def search(self, word: str) -> bool:
        return self.dfs(self.root, word, 0)

    def dfs(self, curr: TrieNode, word: str, index: int) -> bool:
        for i in range(index, len(word)):            
            ch = word[i]
            if ch == '.':
                for child in curr.children.values():
                    if self.dfs(child, word, i+1):
                        return True
                return False
            elif ch not in curr.children:
                return False
            curr = curr.children[ch]
        return curr.end