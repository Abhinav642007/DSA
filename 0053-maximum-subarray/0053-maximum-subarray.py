class Solution(object):
    def maxSubArray(self, nums):
        currsum=0
        maxsum=float('-inf')
        for n in nums:
            currsum+=n
            maxsum=max(currsum,maxsum)

            if(currsum<0):
                currsum=0
        return maxsum

        