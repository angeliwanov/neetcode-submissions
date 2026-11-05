class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        graph = dict()
        for i in range(1, len(order)):
            graph[order[i-1]] = order[i]

        def dfs(ch1, ch2):
            if ch1 not in graph:
                return False
            if graph[ch1] == ch2:
                return True
            return dfs(graph[ch1],ch2)

        for i in range(1, len(words)):
            w1 = words[i-1]
            w2 = words[i]
            min_len = min(len(w1),len(w2))
            if w1[:min_len] == w2[:min_len] and len(w1) > len(w2):
                return False
            for j in range(min_len):
                if w1[j] != w2[j]:
                    if dfs(w1[j],w2[j]):
                        break
                    else:
                        return False

        return True