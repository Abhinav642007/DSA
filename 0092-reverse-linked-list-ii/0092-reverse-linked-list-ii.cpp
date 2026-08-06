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

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        // No reversal needed
        if (!head || left == right)
            return head;

        // Dummy node handles the case when left = 1
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Move prev to the node before 'left'
        ListNode* prev = dummy;
        for (int i = 1; i < left; i++)
            prev = prev->next;

        // First node of the sublist to reverse
        ListNode* curr = prev->next;

        // Reverse using head insertion
        for (int i = 0; i < right - left; i++) {

            // Node to move to the front
            ListNode* nextNode = curr->next;

            // Remove nextNode
            curr->next = nextNode->next;

            // Insert nextNode after prev
            nextNode->next = prev->next;
            prev->next = nextNode;
        }

        return dummy->next;
    }
};