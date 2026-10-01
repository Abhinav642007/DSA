class Solution {
public:
//     vector<int> sortedSquares(vector<int>& nums) {

//     // Square every element
//     for (int i = 0; i < nums.size(); i++) {
//         nums[i] = nums[i] * nums[i];
//     }

//     // Sort the squared values
//     sort(nums.begin(), nums.end());

//     return nums;
// }
    vector<int> sortedSquares(vector<int>& nums) {
    int n = nums.size();

    vector<int> ans(n);

    int left = 0;
    int right = n - 1;

    // Fill answer from the back (largest square first)
    for (int i = n - 1; i >= 0; i--) {

        int leftSquare = nums[left] * nums[left];
        int rightSquare = nums[right] * nums[right];

        if (leftSquare > rightSquare) {
            ans[i] = leftSquare;
            left++;
        }
        else {
            ans[i] = rightSquare;
            right--;
        }
    }

    return ans;
}
};