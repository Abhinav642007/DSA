class Solution {
public:
    string truncateSentence(string s, int k) {
        int spaces = 0;
        string ans = "";

        for (char c : s) {
            if (c == ' ') {
                spaces++;

                if (spaces == k) {
                    break;
                }
            }

            ans += c;
        }

        return ans;
    }
};