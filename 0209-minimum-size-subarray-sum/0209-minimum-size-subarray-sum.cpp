class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int sum = 0;
        int ans = INT_MAX;

        for (int right = 0; right < n; right++) {
            sum += nums[right];  // Window mein element add karo

            while (sum >= target) {
                ans = min(ans, right - left + 1); // Minimum length update karo
                sum -= nums[left];                // Left element hatao
                left++;                           // Window chhoti karo
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};