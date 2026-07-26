class Solution:
    def maximumProduct(self, nums):

        nums.sort(reverse=True)

        n = len(nums)

        product1 = nums[0] * nums[1] * nums[2]
        product2 = nums[0] * nums[n-2] * nums[n-1]

        return max(product1, product2)