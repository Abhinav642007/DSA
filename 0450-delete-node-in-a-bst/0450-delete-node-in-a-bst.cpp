class Solution {
public:

    // Main function: BST me key ko search karke delete karega
    TreeNode* deleteNode(TreeNode* root, int key) {

        // Agar tree empty hai, kuch delete nahi karna
        if (root == NULL) {
            return NULL;
        }

        // Agar root hi delete hone wala node hai
        // Example: root = 5, key = 5
        if (root->val == key) {
            return helper(root);
        }

        // Original root ko save karke rakhenge
        // Kyunki neeche root ko left/right move karenge
        TreeNode* dummy = root;

        // Jab tak node mil nahi jata, BST me search karte rahenge
        while (root != NULL) {

            // Agar key chhoti hai, left subtree me jayegi
            // Example: root = 5, key = 3
            // 5 > 3 → left jao
            if (root->val > key) {

                // Check karo kya current node ka left child hi key hai
                if (root->left != NULL &&
                    root->left->val == key) {

                    // Node mil gaya
                    // helper() us node ko delete karega
                    // Example: 5 -> 3
                    // root->left = helper(3)
                    root->left = helper(root->left);

                    // Deletion ho gayi, ab search ki zarurat nahi
                    break;

                } else {

                    // Target abhi nahi mila
                    // Left subtree me move karo
                    // Example: 5 → 3
                    root = root->left;
                }

            } 
            
            // Agar key badi hai, right subtree me jayegi
            // Example: root = 5, key = 7
            // 5 < 7 → right jao
            else {

                // Check karo kya current node ka right child hi key hai
                if (root->right != NULL &&
                    root->right->val == key) {

                    // Node mil gaya
                    // helper() us node ko delete karega
                    // Example: 5 -> 7
                    root->right = helper(root->right);

                    // Deletion ho gayi
                    break;

                } else {

                    // Target abhi nahi mila
                    // Right subtree me move karo
                    // Example: 5 → 7
                    root = root->right;
                }
            }
        }

        // Original root return karo
        // dummy abhi bhi original root ko point kar raha hai
        return dummy;
    }


    // Ye function already-found node ko delete karta hai
    TreeNode* helper(TreeNode* root) {

        // CASE 1:
        // Left child nahi hai
        // Example:
        //    7
        //     \
        //      8
        //
        // 7 delete → 8 uski jagah aa jayega
        if (root->left == NULL) {
            return root->right;
        }

        // CASE 2:
        // Right child nahi hai
        // Example:
        //    7
        //   /
        //  6
        //
        // 7 delete → 6 uski jagah aa jayega
        else if (root->right == NULL) {
            return root->left;
        }


        // CASE 3:
        // Dono children present hain
        //
        // Example:
        //       7
        //      / \
        //     5   9
        //
        // Pehle right subtree ko save karenge
        TreeNode* rightChild = root->right;


        // Left subtree ka sabse RIGHT/LARGEST node find karo
        //
        // Example:
        //       7
        //      / \
        //     5   9
        //    / \
        //   3   6
        //
        // root->left = 5
        // findLastRight(5) → 6
        TreeNode* lastRight = findLastRight(root->left);


        // Right subtree ko left subtree ke largest node
        // ke right me attach kar do
        //
        // Before:
        //       7
        //      / \
        //     5   9
        //      \
        //       6
        //
        // After:
        //       5
        //        \
        //         6
        //          \
        //           9
        lastRight->right = rightChild;


        // Ab original root delete ho gaya
        // Left subtree ko new root bana do
        return root->left;
    }


    // Left subtree ka sabse RIGHT node find karta hai
    TreeNode* findLastRight(TreeNode* root) {

        // Agar right nahi hai,
        // matlab ye subtree ka largest node hai
        if (root->right == NULL) {
            return root;
        }

        // Right side me continuously jao
        // Example: 5 → 6 → 8
        return findLastRight(root->right);
    }
};