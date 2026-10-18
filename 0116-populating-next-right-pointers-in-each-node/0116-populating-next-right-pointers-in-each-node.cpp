class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr)
            return root;

        Node* leftmost = root;

        while (leftmost->left != nullptr) {
            Node* curr = leftmost;

            while (curr != nullptr) {
                curr->left->next = curr->right;

                if (curr->next != nullptr) {
                    curr->right->next = curr->next->left;
                }

                curr = curr->next;
            }

            leftmost = leftmost->left;
        }

        return root;
    }
};