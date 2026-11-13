class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        graph = defaultdict(list)
        for word in wordList:
            l = len(word)
            dword = word*2
            for i in range(l):        
                graph[dword[i:(i+l-1)]].append(word)
        
        queue = deque([beginWord])
        visited = {beginWord}

        steps = 0   
        while queue:
            steps += 1                        
            length = len(queue)
            for _ in range(length):
                word = queue.popleft()
                if word == endWord:
                    return steps
                l = len(word)
                dword = word*2
                for i in range(l):                            
                    for nei in graph[dword[i:(i+l-1)]]:
                        if nei not in visited:
                            visited.add(nei)
                            queue.append(nei)
        return 0