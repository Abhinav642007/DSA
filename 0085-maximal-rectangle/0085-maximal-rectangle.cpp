class Solution {
public:

    // LeetCode 84:
    // Given histogram heights, find the largest rectangle area
    int largestRectangleArea(vector<int>& heights) {

        stack<int> st;   // Stack mein indices store karenge
        int maxArea = 0;

        // Extra 0 add kar rahe hain taaki
        // last ke remaining bars bhi process ho jayein
        heights.push_back(0);

        for (int i = 0; i < heights.size(); i++) {

            // Agar current height stack ke top se chhoti hai,
            // toh stack ke top wale bar ka rectangle complete ho gaya
            while (!st.empty() && heights[st.top()] > heights[i]) {

                int height = heights[st.top()];
                st.pop();

                // Rectangle ki width calculate karo
                int width;

                if (st.empty()) {
                    // Agar stack empty hai,
                    // rectangle index 0 se start hua tha
                    width = i;
                }
                else {
                    // Stack ke top ke baad se
                    // current index se pehle tak rectangle hai
                    width = i - st.top() - 1;
                }

                // Rectangle area
                int area = height * width;

                // Maximum area update karo
                maxArea = max(maxArea, area);
            }

            // Current index ko stack mein daalo
            st.push(i);
        }

        // Jo 0 add kiya tha usko remove kar do
        heights.pop_back();

        return maxArea;
    }


    // LeetCode 85:
    // Find maximum rectangle containing only 1s
    int maximalRectangle(vector<vector<char>>& matrix) {

        // Agar matrix empty hai
        if (matrix.empty())
            return 0;

        // Number of rows
        int rows = matrix.size();

        // Number of columns
        int cols = matrix[0].size();

        // Har column ki current height
        vector<int> heights(cols, 0);

        // Final maximum answer
        int answer = 0;


        // Har row ko process karo
        for (int i = 0; i < rows; i++) {

            // Current row ke har column ko check karo
            for (int j = 0; j < cols; j++) {

                if (matrix[i][j] == '1') {

                    // Agar 1 hai,
                    // previous height mein 1 add karo
                    heights[j]++;

                }
                else {

                    // Agar 0 hai,
                    // continuous 1s ka chain toot gaya
                    heights[j] = 0;
                }
            }

            // Current heights ko histogram maan kar
            // LeetCode 84 solve karo
            int currentArea = largestRectangleArea(heights);

            // Overall maximum update karo
            answer = max(answer, currentArea);
        }

        return answer;
    }
};