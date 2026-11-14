class Solution {
public:
    int minDiff=INT_MAX;
    void solve(TreeNode* root,TreeNode* &prev){
        if(!root) return;

        solve(root->left,prev);
        
        if(prev!=NULL) {
            minDiff=min(minDiff,root->val-prev->val);
        }
        prev=root;

        solve(root->right,prev);
    }
    int getMinimumDifference(TreeNode* root) {
        TreeNode* prev=NULL;
        solve(root,prev);
        return minDiff;
    }
};