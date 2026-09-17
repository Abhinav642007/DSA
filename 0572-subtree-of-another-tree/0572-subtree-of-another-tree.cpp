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

    // Checks whether two trees are exactly identical
    bool identical(TreeNode* root, TreeNode* subRoot) {

        // Both are NULL → identical
        if (root == NULL && subRoot == NULL)
            return true;

        // One is NULL → not identical
        if (root == NULL || subRoot == NULL)
            return false;

        // Values must match AND left/right subtrees must match
        return root->val == subRoot->val &&
               identical(root->left, subRoot->left) &&
               identical(root->right, subRoot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        // If main tree is finished, subtree wasn't found
        if (root == NULL)
            return false;

        // If current node matches, check complete tree
        if (root->val == subRoot->val &&
            identical(root, subRoot))
            return true;

        // Otherwise search left OR right
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};