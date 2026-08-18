class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();

        // Answer for every element; initially assume no
        // greater element exists.
        vector<int> ans(n, -1);

        // Monotonic decreasing stack.
        // We store indices, not values.
        stack<int> st;

        // Traverse twice to simulate the circular array.
        for (int i = 2 * n - 1; i >= 0; i--) {

            // Convert virtual index into actual array index.
            int idx = i % n;

            // Remove elements that are smaller than or
            // equal to the current value.
            while (!st.empty() && nums[st.top()] <= nums[idx]) {
                st.pop();
            }

            // The top now represents the nearest greater element.
            if (!st.empty()) {
                ans[idx] = nums[st.top()];
            }

            // Store current index for future elements.
            st.push(idx);
        }

        return ans;
    }
};