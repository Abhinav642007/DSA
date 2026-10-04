class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {

        // Agar dono trees hi empty hain
        // toh answer bhi empty hoga
        if(!t1 && !t2) return nullptr;

        // Agar ek tree empty hai,
        // toh doosra tree as it is answer ban jayega
        if(!t1 || !t2)
            return t1 ? t1 : t2;


        // Dono trees ko level-order mein traverse karne ke liye
        // 2 queues banayi
        queue<TreeNode*> q1, q2;

        // Dono trees ke root ko queue mein daal diya
        q1.push(t1);
        q2.push(t2);


        // Jab tak dono queues mein nodes available hain
        while(!q1.empty() && !q2.empty()) {

            // Dono queues ka front node nikala
            TreeNode* c1 = q1.front();
            TreeNode* c2 = q2.front();

            q1.pop();
            q2.pop();


            // Dono corresponding nodes ki values add kar do
            c1->val += c2->val;


            // ---------- LEFT CHILD ----------

            // Agar Tree 1 mein left child nahi hai
            // but Tree 2 mein left child hai
            if(!c1->left && c2->left) {

                // Tree 2 ka left child directly Tree 1 mein attach kar do
                c1->left = c2->left;
            }

            // Agar dono mein left child exist karta hai
            else if(c1->left && c2->left) {

                // Dono corresponding left children ko
                // next process karne ke liye queues mein daal do
                q1.push(c1->left);
                q2.push(c2->left);
            }


            // ---------- RIGHT CHILD ----------

            // Agar Tree 1 mein right child nahi hai
            // but Tree 2 mein right child hai
            if(!c1->right && c2->right) {

                // Tree 2 ka right child Tree 1 mein attach kar do
                c1->right = c2->right;
            }

            // Agar dono mein right child exist karta hai
            else if(c1->right && c2->right) {

                // Dono corresponding right children
                // next processing ke liye queue mein
                q1.push(c1->right);
                q2.push(c2->right);
            }
        }

        // Tree 1 ab merged tree ban chuka hai
        return t1;
    }
};