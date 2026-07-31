class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int j = 0; // Points to the position where the next non-zero should go

        for(int i = 0; i < nums.size(); i++) {

            // If the current element is non-zero,
            // swap it with the element at index j.
            if(nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};