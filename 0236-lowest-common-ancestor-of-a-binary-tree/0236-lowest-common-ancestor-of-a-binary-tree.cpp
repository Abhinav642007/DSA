/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        TreeNode* curr = root;
        
            if(curr == nullptr) {
                return nullptr;
            }
            if(curr == p || curr == q) {
                return curr;
            }

                TreeNode* left = lowestCommonAncestor(curr->left, p, q);
                TreeNode* right = lowestCommonAncestor(curr->right,p ,q);
                if(right != nullptr && left != nullptr){
                    return curr;
                }
            

            if(nullptr!= left) {
                return left;
            }
            return right;
        
        return nullptr;
    }
};