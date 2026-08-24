class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        deque<int> dq;       // Deque me INDEX store karenge
        vector<int> ans;     // Final maximum values

        for (int i = 0; i < nums.size(); i++) {

            // 1. Window se bahar wale index ko remove karo
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // 2. Back se smaller elements remove karo
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            // 3. Current index add karo
            dq.push_back(i);

            // 4. Window complete hone ke baad maximum store karo
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};