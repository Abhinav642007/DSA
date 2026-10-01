class Solution {
    public int[] sortArrayByParity(int[] nums) {

        int left = 0;
        int right = nums.length - 1;

        while (left < right) {

            // If left already has an even number,
            // it is in the correct position.
            if (nums[left] % 2 == 0) {
                left++;
            }

            // If right already has an odd number,
            // it is in the correct position.
            else if (nums[right] % 2 == 1) {
                right--;
            }

            // left = odd and right = even
            // Both are in the wrong position, so swap them.
            else {
                int temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;

                left++;
                right--;
            }
        }

        return nums;
    }
}