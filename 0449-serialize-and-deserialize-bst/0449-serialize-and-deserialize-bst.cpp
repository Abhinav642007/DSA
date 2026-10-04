/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:

    // =========================================================
    // SERIALIZE
    // Tree -> String
    // =========================================================

    string serialize(TreeNode* root) {

        // Agar tree empty hai
        if (root == NULL)
            return "";

        string ans = "";

        // Level order traversal ke liye queue
        queue<TreeNode*> q;

        // Root se start
        q.push(root);

        while (!q.empty()) {

            // Queue se current node nikalo
            TreeNode* node = q.front();
            q.pop();

            // Agar NULL hai
            if (node == NULL) {

                // NULL ko # se represent karenge
                ans += "#,";
            }

            else {

                // Node ki value string mein add karo
                ans += to_string(node->val) + ",";

                // Left child queue mein
                q.push(node->left);

                // Right child queue mein
                q.push(node->right);
            }
        }

        return ans;
    }


    // =========================================================
    // DESERIALIZE
    // String -> Tree
    // =========================================================

    TreeNode* deserialize(string data) {

        // Agar data empty hai
        if (data == "")
            return NULL;


        // data ko ek-ek value karke read karenge
        stringstream s(data);

        string str;


        // -----------------------------------------------------
        // ROOT
        // -----------------------------------------------------

        // First value read karo
        //
        // Example:
        // data = "1,2,3,#,#,4,5,#,#,#,#,"
        //
        // First getline:
        // str = "1"

        getline(s, str, ',');


        // Root node create karo
        TreeNode* root = new TreeNode(stoi(str));


        // Root ko queue mein daalo
        queue<TreeNode*> q;
        q.push(root);


        // -----------------------------------------------------
        // CHILDREN CREATE KARNA
        // -----------------------------------------------------

        while (!q.empty()) {

            // Queue se parent nikalo
            TreeNode* node = q.front();
            q.pop();


            // =================================================
            // LEFT CHILD
            // =================================================

            // Next value read karo
            getline(s, str, ',');


            // Agar # hai
            // matlab left child NULL hai
            if (str == "#") {

                node->left = NULL;
            }

            else {

                // Actual node hai
                node->left = new TreeNode(stoi(str));

                // Is node ke future children bhi banenge
                q.push(node->left);
            }


            // =================================================
            // RIGHT CHILD
            // =================================================

            // Next value read karo
            getline(s, str, ',');


            // Agar # hai
            // matlab right child NULL hai
            if (str == "#") {

                node->right = NULL;
            }

            else {

                // Actual node create karo
                node->right = new TreeNode(stoi(str));

                // Future mein iske children banane ke liye
                // queue mein daalo
                q.push(node->right);
            }
        }


        // Complete tree return
        return root;
    }
};