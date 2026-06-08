class Solution:
    def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:
        subSum = 0
        subArr = 0

        for i in range(k-1):
            subSum += arr[i]
        
        for i in range(k-1, len(arr)):
            subSum += arr[i]
            if subSum / k >= threshold:
                subArr += 1
            subSum -= arr[i+1-k]
        
        return subArr