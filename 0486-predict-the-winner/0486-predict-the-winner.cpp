class Solution {
public:
    // Returns the maximum score difference the current player
    // can achieve over the opponent from nums[left...right]
    int solve(int left, int right, vector<int>& nums, vector<vector<int>>& dp) {

        // Base case: only one element left
        if (left == right)
            return nums[left];

        // Return the stored result if already computed
        if (dp[left][right] != INT_MIN)
            return dp[left][right];

        // Pick the left element
        int pickLeft = nums[left] - solve(left + 1, right, nums, dp);

        // Pick the right element
        int pickRight = nums[right] - solve(left, right - 1, nums, dp);

        // Store and return the best score difference
        return dp[left][right] = max(pickLeft, pickRight);
    }

    bool predictTheWinner(vector<int>& nums) {

        int n = nums.size();

        // DP table initialized with INT_MIN (unvisited)
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));

        // If Player 1 can achieve a non-negative score difference,
        // they can win or tie.
        return solve(0, n - 1, nums, dp) >= 0;
    }
};