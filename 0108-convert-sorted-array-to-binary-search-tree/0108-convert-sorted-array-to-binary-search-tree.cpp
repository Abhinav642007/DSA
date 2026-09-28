class Solution {
public:
    TreeNode* build(vector<int>& nums, int left, int right) {

        if (left > right)
            return nullptr;

        // Choose middle element as root
        int mid = left + (right - left) / 2;

        TreeNode* root = new TreeNode(nums[mid]);

        // Build left subtree
        root->left = build(nums, left, mid - 1);

        // Build right subtree
        root->right = build(nums, mid + 1, right);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums, 0, nums.size() - 1);
    }
};