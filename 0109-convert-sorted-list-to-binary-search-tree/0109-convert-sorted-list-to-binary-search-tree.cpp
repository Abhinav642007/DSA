/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    TreeNode* sortedListToBST(ListNode* head) {

        // Empty list
        if (head == nullptr)
            return nullptr;

        // Only one node
        if (head->next == nullptr)
            return new TreeNode(head->val);

        // Find middle
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast != nullptr && fast->next != nullptr) {

            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // slow is middle
        TreeNode* root = new TreeNode(slow->val);

        // Break left half
        prev->next = nullptr;

        // Left half
        root->left = sortedListToBST(head);

        // Right half
        root->right = sortedListToBST(slow->next);

        return root;
    }
};