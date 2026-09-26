class Solution {
public:

    void allpaths(TreeNode* root, string path, vector<string>& ans) {
        
        // Leaf node
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(path);
            return;
        }

        // Go to left subtree
        if (root->left) {
            allpaths(
                root->left,
                path + "->" + to_string(root->left->val),
                ans
            );
        }

        // Go to right subtree
        if (root->right) {
            allpaths(
                root->right,
                path + "->" + to_string(root->right->val),
                ans
            );
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;

        if (root == NULL)
            return ans;

        string path = to_string(root->val);

        allpaths(root, path, ans);

        return ans;
    }
};