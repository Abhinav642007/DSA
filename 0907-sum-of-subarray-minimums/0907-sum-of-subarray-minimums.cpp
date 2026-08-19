class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {

        int n = arr.size();
        const long long MOD = 1e9 + 7;

        // left[i] = index of previous smaller element
        vector<int> left(n);

        // right[i] = index of next smaller element
        vector<int> right(n);

        stack<int> st;

        // ----------------------------------------
        // 1. Find Previous Smaller Element
        // ----------------------------------------
        for (int i = 0; i < n; i++) {

            // Remove elements greater than current
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            // If no smaller element exists on left
            if (st.empty())
                left[i] = -1;
            else
                left[i] = st.top();

            // Store current index
            st.push(i);
        }

        // Clear stack
        while (!st.empty()) {
            st.pop();
        }

        // ----------------------------------------
        // 2. Find Next Smaller Element
        // ----------------------------------------
        for (int i = n - 1; i >= 0; i--) {

            // Remove elements greater than or equal
            // to current element
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            // If no smaller element exists on right
            if (st.empty())
                right[i] = n;
            else
                right[i] = st.top();

            // Store current index
            st.push(i);
        }

        // ----------------------------------------
        // 3. Calculate every element's contribution
        // ----------------------------------------
        long long ans = 0;

        for (int i = 0; i < n; i++) {

            // Number of possible starting positions
            long long leftChoices = i - left[i];

            // Number of possible ending positions
            long long rightChoices = right[i] - i;

            // Contribution of arr[i]
            long long contribution =
                1LL * arr[i] * leftChoices * rightChoices;

            // Add contribution to final answer
            ans = (ans + contribution) % MOD;
        }

        return ans;
    }
};