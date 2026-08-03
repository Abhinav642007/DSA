class Solution {
public:
    vector<int> dp;

    int solve(int i, vector<int>& stoneValue) {

        // No stones left
        if (i >= stoneValue.size())
            return 0;

        // Already computed
        if (dp[i] != INT_MIN)
            return dp[i];

        int take = 0;
        int ans = INT_MIN;

        // Take 1, 2, or 3 stones
        for (int k = 0; k < 3 && i + k < stoneValue.size(); k++) {

            take += stoneValue[i + k];

            ans = max(ans, take - solve(i + k + 1, stoneValue));
        }

        return dp[i] = ans;
    }

    string stoneGameIII(vector<int>& stoneValue) {

        dp.assign(stoneValue.size(), INT_MIN);

        int diff = solve(0, stoneValue);

        if (diff > 0)
            return "Alice";

        if (diff < 0)
            return "Bob";

        return "Tie";
    }
};