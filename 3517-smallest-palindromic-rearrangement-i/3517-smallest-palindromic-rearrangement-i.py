class Solution(object):
    def smallestPalindrome(self, s):

        partition = len(s) // 2

        bucket = [0] * 26

        for i in range(partition):
            bucket[ord(s[i]) - ord('a')] += 1

        left = ""

        for i in range(26):
            left += chr(i + ord('a')) * bucket[i]

        mid = s[partition] if len(s) % 2 else ""

        right = left[::-1]

        return left + mid + right