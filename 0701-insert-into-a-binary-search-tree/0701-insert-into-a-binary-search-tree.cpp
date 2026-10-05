class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {

        // Empty tree
        if (root == NULL)
            return new TreeNode(val);

        TreeNode* cur = root;

        while (true) {

            // val should go to the RIGHT
            if (cur->val <= val) {

                // Right child exists → move right
                if (cur->right != NULL) {
                    cur = cur->right;
                }

                // Right child doesn't exist → insert here
                else {
                    cur->right = new TreeNode(val);
                    break;
                }
            }

            // val should go to the LEFT
            else {

                // Left child exists → move left
                if (cur->left != NULL) {
                    cur = cur->left;
                }

                // Left child doesn't exist → insert here
                else {
                    cur->left = new TreeNode(val);
                    break;
                }
            }
        }

        return root;
    }
};