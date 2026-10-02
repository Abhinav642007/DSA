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

    void collectDown(TreeNode* root, int k, vector<int>& ans) {

        // No node
        if (root == NULL)
            return;

        // Exactly k distance reached
        if (k == 0) {
            ans.push_back(root->val);
            return;
        }

        // Go down both sides
        collectDown(root->left, k - 1, ans);
        collectDown(root->right, k - 1, ans);
    }


    int solve(TreeNode* root, TreeNode* target, int k,
              vector<int>& ans) {

        // Target not found
        if (root == NULL)
            return -1;


        // -------------------------
        // CASE 1: Current node = target
        // -------------------------

        if (root == target) {

            // Find nodes k distance DOWNWARD
            collectDown(root, k, ans);

            // Target found at distance 0
            return 0;
        }


        // Search target in LEFT subtree
        int dl = solve(root->left, target, k, ans);

        if (dl != -1) {

            // Distance from current root to target
            int distance = dl + 1;


            // -------------------------
            // CASE 2A: Ancestor itself
            // -------------------------

            if (distance == k) {
                ans.push_back(root->val);
            }


            // -------------------------
            // CASE 2B: Target is in LEFT
            // Search opposite RIGHT subtree
            // -------------------------

            else {
                int remaining = k - distance - 1;

                if (remaining >= 0)
                    collectDown(root->right, remaining, ans);
            }

            return distance;
        }


        // Search target in RIGHT subtree
        int dr = solve(root->right, target, k, ans);

        if (dr != -1) {

            // Distance from current root to target
            int distance = dr + 1;


            // -------------------------
            // CASE 2A: Ancestor itself
            // -------------------------

            if (distance == k) {
                ans.push_back(root->val);
            }


            // -------------------------
            // CASE 2B: Target is in RIGHT
            // Search opposite LEFT subtree
            // -------------------------

            else {
                int remaining = k - distance - 1;

                if (remaining >= 0)
                    collectDown(root->left, remaining, ans);
            }

            return distance;
        }


        // Target doesn't exist in this subtree
        return -1;
    }


    vector<int> distanceK(TreeNode* root,
                          TreeNode* target,
                          int k) {

        vector<int> ans;

        solve(root, target, k, ans);

        return ans;
    }
};