class Solution {
public:

    // ------------------------------------------------
    // LeetCode 84: Largest Rectangle in Histogram
    // ------------------------------------------------
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();

        vector<int> prev(n);
        vector<int> next(n);

        stack<int> st;


        // ---------------------------------------------
        // 1. Previous Smaller Element
        // ---------------------------------------------

        for (int i = 0; i < n; i++) {

            // Greater or equal elements ko remove karo
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            // Agar koi smaller element left mein nahi hai
            if (st.empty())
                prev[i] = -1;
            else
                prev[i] = st.top();

            // Current INDEX stack mein store karo
            st.push(i);
        }


        // Stack clear karo
        while (!st.empty())
            st.pop();


        // ---------------------------------------------
        // 2. Next Smaller Element
        // ---------------------------------------------

        for (int i = n - 1; i >= 0; i--) {

            // Greater or equal elements ko remove karo
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            // Agar right mein koi smaller element nahi hai
            if (st.empty())
                next[i] = n;
            else
                next[i] = st.top();

            // Current INDEX stack mein store karo
            st.push(i);
        }


        // ---------------------------------------------
        // 3. Calculate Maximum Area
        // ---------------------------------------------

        int maxArea = 0;

        for (int i = 0; i < n; i++) {

            // Previous smaller aur next smaller ke
            // beech ka total width
            int width = next[i] - prev[i] - 1;

            // Rectangle area
            int area = heights[i] * width;

            // Maximum area update
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }


    // ------------------------------------------------
    // LeetCode 85: Maximal Rectangle
    // ------------------------------------------------
    int maximalRectangle(vector<vector<char>>& matrix) {

        // Agar matrix empty hai
        if (matrix.empty())
            return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();

        // Har column ki current height
        vector<int> heights(cols, 0);

        // Final answer
        int answer = 0;


        // Har row ko process karo
        for (int i = 0; i < rows; i++) {

            // Current row ke har column ko check karo
            for (int j = 0; j < cols; j++) {

                if (matrix[i][j] == '1') {

                    // Agar current cell 1 hai,
                    // toh consecutive height mein 1 add karo
                    heights[j]++;

                }
                else {

                    // Agar 0 mila,
                    // toh consecutive 1s ka chain toot gaya
                    heights[j] = 0;
                }
            }


            // Current row ke heights ko histogram samjho
            // aur LC 84 ka function use karo
            int currentArea = largestRectangleArea(heights);

            // Overall maximum update karo
            answer = max(answer, currentArea);
        }

        return answer;
    }
};