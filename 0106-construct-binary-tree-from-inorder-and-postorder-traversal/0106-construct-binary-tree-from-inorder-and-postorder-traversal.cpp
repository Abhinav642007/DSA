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

    unordered_map<int, int> mp;
    int postIndex;

    TreeNode* solve(vector<int>& inorder,
                    vector<int>& postorder,
                    int inStart,
                    int inEnd) {

        // No elements left
        if (inStart > inEnd)
            return nullptr;

        // Postorder ka last element root hota hai
        int rootValue = postorder[postIndex--];

        // Root node banao
        TreeNode* root = new TreeNode(rootValue);

        // Inorder mein root ki position
        int mid = mp[rootValue];

        // IMPORTANT:
        // Postorder mein root ke pehle RIGHT subtree aata hai
        root->right = solve(inorder, postorder,
                            mid + 1, inEnd);

        // Uske baad LEFT subtree
        root->left = solve(inorder, postorder,
                           inStart, mid - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder,
                        vector<int>& postorder) {

        // Inorder ki positions store karo
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        // Postorder ka last index
        postIndex = postorder.size() - 1;

        return solve(inorder, postorder,
                     0, inorder.size() - 1);
    }
};