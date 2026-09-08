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
    int maxDepth(TreeNode* root) {

        // Base case
        if (root == NULL)
            return 0;

        // Find left subtree depth
        int lh = maxDepth(root->left);

        // Find right subtree depth
        int rh = maxDepth(root->right);

        // Current node + deeper subtree
        return 1 + max(lh, rh);
    }
};