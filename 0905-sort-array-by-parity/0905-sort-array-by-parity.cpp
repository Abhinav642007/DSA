class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {

        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {

            // If left already has EVEN number,
            // it is in the correct position.
            if (nums[left] % 2 == 0) {
                left++;
            }

            // If right already has ODD number,
            // it is in the correct position.
            else if (nums[right] % 2 != 0) {
                right--;
            }

            // left = ODD and right = EVEN
            // Both are in wrong positions, so swap.
            else {
                swap(nums[left], nums[right]);

                left++;
                right--;
            }
        }

        return nums;
    }
};