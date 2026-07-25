class Solution(object):
    def maxProduct(self, n):
        arr=[int(a) for a in str(n)]
        arr.sort(reverse=True)
        max_p=arr[0]*arr[1]
        return max_p
            
