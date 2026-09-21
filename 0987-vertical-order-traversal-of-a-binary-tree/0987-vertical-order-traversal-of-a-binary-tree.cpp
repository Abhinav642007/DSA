class Solution {
public:

    void solve(TreeNode* root, int row, int col,
               map<int, map<int, multiset<int>>>& mp) {

        if (root == NULL)
            return;

        mp[col][row].insert(root->val);

        solve(root->left, row + 1, col - 1, mp);
        solve(root->right, row + 1, col + 1, mp);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {

        map<int, map<int, multiset<int>>> mp;

        solve(root, 0, 0, mp);

        vector<vector<int>> ans;

        for (auto &col : mp) {

            vector<int> temp;

            for (auto &row : col.second) {

                for (int value : row.second) {
                    temp.push_back(value);
                }
            }

            ans.push_back(temp);
        }

        return ans;
    }
};