/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    TreeNode* solve(vector<int>& nums, int left, int right) {

        // 1. Agar range empty hai, node nahi bana sakte
        if (left > right)
            return nullptr;

        // 2. Middle index find karo
        int mid = left + (right - left) / 2;

        // 3. Middle element ko root banao
        TreeNode* root = new TreeNode(nums[mid]);

        // 4. Middle ke left wale elements se left subtree banao
        root->left = solve(nums, left, mid - 1);

        // 5. Middle ke right wale elements se right subtree banao
        root->right = solve(nums, mid + 1, right);

        // 6. Root return karo
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {

        // Puri array ko process karo
        return solve(nums, 0, nums.size() - 1);
    }
};