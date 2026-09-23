class Solution:
    def findInMountainArray(self, target: int, mountainArr: 'MountainArray') -> int:
        def ma(l,r):
            while l <= r:
                m = l + (r-l) // 2
                if mountainArr.get(m) > mountainArr.get(m-1) and mountainArr.get(m) > mountainArr.get(m+1):
                    return m
                elif mountainArr.get(m) < mountainArr.get(m+1):
                    l = m + 1
                else:
                    r = m - 1
            return - 1
        def bs(l,r):
            while l <= r:
                m = l + (r-l) // 2
                if mountainArr.get(m) == target:
                    return m
                elif mountainArr.get(m) > target:
                    r = m - 1
                else:
                    l = m + 1
            return -1
        def bsr(l,r):
            while l <= r:
                m = l + (r-l) // 2
                if mountainArr.get(m) == target:
                    return m
                elif mountainArr.get(m) > target:
                    l = m + 1
                else:
                    r = m - 1
            return -1
        m = ma(0,mountainArr.length()-1)
        l = bs(0, m)
        r = bsr(m, mountainArr.length()-1)

        return l if l != -1 else r
                