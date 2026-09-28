class Solution {
public:
    TreeNode* solve(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while (fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if (prev == NULL) {
            return new TreeNode(slow->val);
        }

        prev->next = NULL;

        TreeNode* root = new TreeNode(slow->val);

        root->left = solve(head);
        root->right = solve(slow->next);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        return solve(head);
    }
};