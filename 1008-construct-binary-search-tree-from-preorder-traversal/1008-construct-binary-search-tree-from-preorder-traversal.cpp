
class Solution {
public:
    TreeNode* insert(vector<int>& preorder, int &i, int bound) {

        // if (root == NULL) {
        //     return new TreeNode(val);
        // }

        // if (val < root->val) {
        //     root->left = insert(root->left, val);
        // } else {
        //     root->right = insert(root->right, val);
        // }

        // return root;

        if(i >= preorder.size() || preorder[i] > bound) return NULL;

        TreeNode* root = new TreeNode (preorder[i++]);

        root->left = insert(preorder,i,root->val);
        root->right = insert(preorder,i,bound);
        return root ;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // TreeNode* root = NULL;

        // for (int val : preorder) {
        //     root = insert(root, val);
        // }

        // return root;



        int i =0;
        return insert(preorder,i,INT_MAX);
    }
};



