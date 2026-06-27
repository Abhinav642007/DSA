import math

class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        root = math.isqrt(num)
        return root * root == num