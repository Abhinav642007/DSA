class Solution {
public:
    int maximumProduct(vector<int>& nums) {

        // 3 largest numbers
        int max1 = INT_MIN;
        int max2 = INT_MIN;
        int max3 = INT_MIN;

        // 2 smallest numbers
        int min1 = INT_MAX;
        int min2 = INT_MAX;

        for (int x : nums) {

            // Find 3 largest
            if (x > max1) {
                max3 = max2;
                max2 = max1;
                max1 = x;
            }
            else if (x > max2) {
                max3 = max2;
                max2 = x;
            }
            else if (x > max3) {
                max3 = x;
            }

            // Find 2 smallest
            if (x < min1) {
                min2 = min1;
                min1 = x;
            }
            else if (x < min2) {
                min2 = x;
            }
        }

        // Either:
        // 1. Three largest
        // 2. Two smallest (negative) + largest
        return max(
            max1 * max2 * max3,
            min1 * min2 * max1
        );
    }
};