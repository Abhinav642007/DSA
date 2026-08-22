class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        int k = 0;  // Position where the next valid element will be placed

        for (int i = 0; i < nums.size(); i++) {

            // If current element is NOT equal to val
            if (nums[i] != val) {

                nums[k] = nums[i];  // Put valid element at position k
                k++;                // Move k forward
            }
        }

        return k;  // Number of elements remaining
    }
};