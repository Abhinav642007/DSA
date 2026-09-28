class Solution {
public:
    unordered_map<int, int> mp;
    int preIndex = 0;

    TreeNode* solve(vector<int>& preorder, int inStart, int inEnd) {

        // No elements
        if (inStart > inEnd)
            return nullptr;

        // Preorder gives the root
        int rootValue = preorder[preIndex++];

        TreeNode* root = new TreeNode(rootValue);

        // Find root in inorder
        int inIndex = mp[rootValue];

        // Build left subtree
        root->left = solve(preorder, inStart, inIndex - 1);

        // Build right subtree
        root->right = solve(preorder, inIndex + 1, inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        // Store inorder value -> index
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        return solve(preorder, 0, inorder.size() - 1);
    }
};