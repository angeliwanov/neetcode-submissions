class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:                
        visited = set(deadends)        
        q = deque()
        if '0000' not in visited:
            q.append('0000')
        moves = 0
        while q:
            length = len(q)
            for _ in range(length):
                comb = q.popleft()
                if comb == target:
                    return moves
                for digit in range(4):
                    for change in [-1,1]:
                        new = comb[:digit] + str((int(comb[digit]) + change)%10) + comb[digit+1:]
                        if new not in visited:
                            visited.add(new)
                            q.append(new)
            moves += 1

        return -1