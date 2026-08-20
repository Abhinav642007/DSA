
        // long long ans = 0;
        // int n = nums.size();

        // for (int i = 0; i < n; i++) {

        //     int mini = nums[i];
        //     int maxi = nums[i];

        //     for (int j = i; j < n; j++) {

        //         // Update minimum and maximum
        //         mini = min(mini, nums[j]);
        //         maxi = max(maxi, nums[j]);

        //         // Add current subarray's range
        //         ans += maxi - mini;
        //     }
        // }

        // return ans;

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {

        int n = nums.size();

        long long sumMax = 0;
        long long sumMin = 0;

        // --------------------------------
        // SUM OF SUBARRAY MAXIMUMS
        // --------------------------------

        vector<int> left(n), right(n);
        stack<int> st;

        // Previous Greater
        for (int i = 0; i < n; i++) {

            // Remove smaller or equal elements
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }

            left[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        // Clear stack
        while (!st.empty())
            st.pop();

        // Next Greater
        for (int i = n - 1; i >= 0; i--) {

            // Remove smaller elements
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }

            right[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        // Calculate maximum contribution
        for (int i = 0; i < n; i++) {

            long long leftChoices = i - left[i];
            long long rightChoices = right[i] - i;

            sumMax += 1LL * nums[i] *
                      leftChoices *
                      rightChoices;
        }


        // --------------------------------
        // SUM OF SUBARRAY MINIMUMS
        // --------------------------------

        while (!st.empty())
            st.pop();

        // Previous Smaller
        for (int i = 0; i < n; i++) {

            // Remove greater or equal elements
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }

            left[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        // Clear stack
        while (!st.empty())
            st.pop();

        // Next Smaller
        for (int i = n - 1; i >= 0; i--) {

            // Remove greater elements
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }

            right[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        // Calculate minimum contribution
        for (int i = 0; i < n; i++) {

            long long leftChoices = i - left[i];
            long long rightChoices = right[i] - i;

            sumMin += 1LL * nums[i] *
                      leftChoices *
                      rightChoices;
        }

        // Range = Maximum - Minimum
        return sumMax - sumMin;
    }
};