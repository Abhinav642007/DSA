class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int n = nums.size();   // Numbers are from 0 to n

        int expectedSum = n * (n + 1) / 2;

        int actualSum = 0;

        // Calculate sum of all elements
        for (int num : nums) {
            actualSum += num;
        }

        // Missing number
        return expectedSum - actualSum;
    }
};