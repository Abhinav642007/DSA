/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        // If the list is empty or has only one node,
        // then a cycle cannot exist.
        if (head == NULL || head->next == NULL)
            return NULL;

        // Initialize slow and fast pointers.
        ListNode *slow = head;
        ListNode *fast = head;

        // Step 1: Detect if a cycle exists.
        while (fast != NULL && fast->next != NULL) {

            // Slow pointer moves one step.
            slow = slow->next;

            // Fast pointer moves two steps.
            fast = fast->next->next;

            // If both pointers meet, a cycle exists.
            if (slow == fast) {

                // Move slow pointer back to the head.
                slow = head;

                // Move both pointers one step at a time.
                // They will meet at the starting node of the cycle.
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }

                // Return the starting node of the cycle.
                return slow;
            }
        }

        // No cycle exists.
        return NULL;
    }
};