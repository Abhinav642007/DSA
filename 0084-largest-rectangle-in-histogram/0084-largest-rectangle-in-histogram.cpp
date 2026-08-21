// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {

//         int n = heights.size();

//         // Stack stores indices of bars
//         // in increasing height order
//         stack<int> st;

//         int maxArea = 0;

//         // Go one extra step with height 0
//         // This forces us to process all remaining bars
//         for (int i = 0; i <= n; i++) {

//             // If i == n, assume current height = 0
//           x  // Otherwise take the actual height
//             int currentHeight = (i == n) ? 0 : heights[i];

//             // If current bar is smaller than stack top,
//             // the stack-top bar cannot extend further right
//             while (!st.empty() &&
//                    heights[st.top()] > currentHeight) {

//                 // This bar is now being removed
//                 int index = st.top();
//                 st.pop();

//                 // Height of the rectangle
//                 int height = heights[index];

//                 // i = Next Smaller Element (NSE)

//                 int width;

//                 if (st.empty()) {

//                     // No Previous Smaller Element (PSE)
//                     // So rectangle extends from index 0 to i-1
//                     width = i;

//                 } else {

//                     // st.top() = Previous Smaller Element (PSE)
//                     //
//                     // i = Next Smaller Element (NSE)
//                     //
//                     // Therefore:
//                     // width = NSE - PSE - 1
//                     width = i - st.top() - 1;
//                 }

//                 // Rectangle area
//                 int area = height * width;

//                 // Keep the largest area
//                 maxArea = max(maxArea, area);
//             }

//             // Store current index for future comparisons
//             st.push(i);
//         }

//         return maxArea;
//     }
// };
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();

        vector<int> prev(n);
        vector<int> next(n);

        stack<int> st;

        // -------------------------------
        // 1. Previous Smaller Element
        // -------------------------------

        for (int i = 0; i < n; i++) {

            // Remove greater/equal heights
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            // If stack is empty, no smaller element on left
            if (st.empty())
                prev[i] = -1;
            else
                prev[i] = st.top();

            // Store INDEX
            st.push(i);
        }


        // Clear stack for next calculation
        while (!st.empty())
            st.pop();


        // -------------------------------
        // 2. Next Smaller Element
        // -------------------------------

        for (int i = n - 1; i >= 0; i--) {

            // Remove greater/equal heights
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            // If stack is empty, no smaller element on right
            if (st.empty())
                next[i] = n;
            else
                next[i] = st.top();

            // Store INDEX
            st.push(i);
        }


        // -------------------------------
        // 3. Calculate Maximum Area
        // -------------------------------

        int maxArea = 0;

        for (int i = 0; i < n; i++) {

            // Width between previous smaller and next smaller
            int width = next[i] - prev[i] - 1;

            // Area = height × width
            int area = heights[i] * width;

            // Update maximum
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};