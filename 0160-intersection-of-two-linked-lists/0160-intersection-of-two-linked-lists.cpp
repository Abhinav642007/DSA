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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        // Pointer for first linked list
        ListNode* ptrA = headA;

        // Pointer for second linked list
        ListNode* ptrB = headB;

        // Continue until both pointers meet
        while (ptrA != ptrB) {

            // If end of List A is reached,
            // start traversing List B
            if (ptrA == NULL)
                ptrA = headB;
            else
                ptrA = ptrA->next;

            // If end of List B is reached,
            // start traversing List A
            if (ptrB == NULL)
                ptrB = headA;
            else
                ptrB = ptrB->next;
        }

        // Either intersection node or NULL
        return ptrA;
    }
};