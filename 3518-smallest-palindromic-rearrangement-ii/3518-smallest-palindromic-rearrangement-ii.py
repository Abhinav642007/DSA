from collections import Counter
from math import comb

class Solution:
    def smallestPalindrome(self, s: str, k: int) -> str:
        LIMIT = 10**6 + 1

        cnt = Counter(s)

        half = [0] * 26
        mid = ""

        for ch, f in cnt.items():
            half[ord(ch) - ord('a')] = f // 2
            if f % 2:
                mid = ch

        def ways(freq):
            res = 1
            remain = sum(freq)

            for f in freq:
                if f:
                    res *= comb(remain, f)
                    remain -= f
                    if res >= LIMIT:
                        return LIMIT
            return res

        if ways(half) < k:
            return ""

        left = []

        while sum(half):
            for i in range(26):
                if half[i] == 0:
                    continue

                half[i] -= 1
                cntWays = ways(half)

                if cntWays >= k:
                    left.append(chr(i + ord('a')))
                    break

                k -= cntWays
                half[i] += 1

        left = "".join(left)
        return left + mid + left[::-1]