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

    // Function to reverse a linked list
    ListNode* reverse(ListNode* head) {

        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {

            // Store next node
            ListNode* front = curr->next;

            // Reverse link
            curr->next = prev;

            // Move pointers
            prev = curr;
            curr = front;
        }

        return prev;
    }

    // Returns the kth node from the current node
    ListNode* findkthnode(ListNode* temp, int k) {

        k--;

        while (temp != NULL && k > 0) {
            temp = temp->next;
            k--;
        }

        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* temp = head;
        ListNode* prevNode = NULL;

        while (temp != NULL) {

            // Find kth node
            ListNode* kthNode = findkthnode(temp, k);

            // Less than k nodes remain
            if (kthNode == NULL) {

                if (prevNode != NULL)
                    prevNode->next = temp;

                break;
            }

            // Store next group's starting node
            ListNode* nextNode = kthNode->next;

            // Break current group
            kthNode->next = NULL;

            // Reverse current group
            reverse(temp);

            // First reversed group becomes new head
            if (temp == head) {
                head = kthNode;
            }
            else {
                prevNode->next = kthNode;
            }

            // Current head becomes last after reversal
            prevNode = temp;

            // Move to next group
            temp = nextNode;
        }

        return head;
    }
};