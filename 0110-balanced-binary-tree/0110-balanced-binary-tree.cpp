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
    int height(TreeNode* node){
        //empty tree
        if(node==NULL) return 0;

        int lh = height(node->left);
        //left subtree unbalanced
        if(lh==-1) return -1;

        int rh = height(node->right);
        //right subtree unbalanced
        if(rh==-1) return -1;


        // current node is unbalanced
        if(abs(lh-rh)>1) return -1;

        // return height
        return 1+max(lh,rh);

    }



    bool isBalanced(TreeNode* root) {
        return height(root)!=-1;
    }
};