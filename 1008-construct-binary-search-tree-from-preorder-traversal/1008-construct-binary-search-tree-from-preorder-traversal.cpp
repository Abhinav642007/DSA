
class Solution {
public:
    TreeNode* insert(TreeNode* root, int val) {
        if (root == NULL) {
            return new TreeNode(val);
        }

        if (val < root->val) {
            root->left = insert(root->left, val);
        } else {
            root->right = insert(root->right, val);
        }

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = NULL;

        for (int val : preorder) {
            root = insert(root, val);
        }

        return root;
    }
};



