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

    // Merge two sorted linked lists
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        // Dummy node to simplify insertion
        ListNode* dummy = new ListNode(-1);

        // Points to the last node of merged list
        ListNode* temp = dummy;

        // Compare both lists until one becomes empty
        while (list1 != NULL && list2 != NULL) {

            // Pick the smaller node
            if (list1->val <= list2->val) {

                temp->next = list1;
                list1 = list1->next;
            }
            else {

                temp->next = list2;
                list2 = list2->next;
            }

            // Move temp forward
            temp = temp->next;
        }

        // Attach remaining nodes
        if (list1 != NULL)
            temp->next = list1;
        else
            temp->next = list2;

        // Return merged list
        return dummy->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        // Edge case
        if (lists.empty())
            return NULL;

        // Start with first linked list
        ListNode* head = lists[0];

        // Merge one list at a time
        for (int i = 1; i < lists.size(); i++) {

            head = mergeTwoLists(head, lists[i]);
        }

        return head;
    }
};
