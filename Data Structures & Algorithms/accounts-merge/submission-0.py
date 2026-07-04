class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        def find(n):
            p = parent[n]
            while p != parent[p]:
                parent[p] = parent[parent[p]]
                p = parent[p]
            return p

        def union(n1, n2):
            p1 = find(n1)
            p2 = find(n2)

            if p1 == p2:
                return False

            if rank[p1] > rank[p2]:
                rank[p1] += rank[p2]
                parent[p2] = p1
            else:
                rank[p2] += rank[p1]
                parent[p1] = p2
            return True
        
        parent = [i for i in range(len(accounts))]
        rank = [1 for _ in range(len(accounts))]
        emails = {}

        for index, account in enumerate(accounts):
            for email in account[1:]:
                if email in emails:
                    union(index, emails[email])
                else:
                    emails[email] = index
        groups = defaultdict(list)

        for email, index in emails.items():
            par = find(index)
            groups[par].append(email)

        
        result = []
        for par, emails in groups.items():
            name = accounts[par][0]            
            result.append([name] + sorted(emails))

        return result
        

        
    