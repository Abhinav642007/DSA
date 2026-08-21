class Solution {
public:
    int strStr(string haystack, string needle) {

        // If needle is empty, return 0
        if (needle.empty())
            return 0;

        int n = haystack.size();
        int m = needle.size();

        // Try every possible starting position
        for (int i = 0; i <= n - m; i++) {

            int j = 0;

            // Compare haystack substring with needle
            while (j < m && haystack[i + j] == needle[j]) {
                j++;
            }

            // If complete needle matched
            if (j == m)
                return i;
        }

        // Needle not found
        return -1;
    }
};