class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        // Stores all elements for O(1) lookup
        unordered_set<int> st;

        // Variables to store smallest and largest values
        int mn = INT_MAX;
        int mx = INT_MIN;

        // Traverse the array
        for (int num : nums) {

            // Update minimum element
            mn = min(mn, num);

            // Update maximum element
            mx = max(mx, num);

            // Store current element
            st.insert(num);
        }

        vector<int> ans;

        // Check every number between minimum and maximum
        for (int i = mn + 1; i < mx; i++) {

            // If number is absent, it is missing
            if (st.find(i) == st.end()) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};