class Solution:
    def maxTurbulenceSize(self, arr: List[int]) -> int:
        max_len = 1
        left = 0
        compare = 0

        for right in range(1, len(arr)):
            if arr[right] == arr[right-1]:
                left = right
                compare = 0
            else:
                if arr[right] > arr[right-1]:
                    if compare == 1:
                        left = right - 1
                    compare = 1
                else:
                    if compare == -1:
                        left = right - 1
                    compare = -1
            max_len = max(max_len, right - left + 1)
        
        return max_len