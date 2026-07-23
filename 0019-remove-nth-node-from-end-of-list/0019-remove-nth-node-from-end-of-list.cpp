
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* temp = head;
        int counter = 0;

        // Count the number of nodes
        while (temp != NULL) {
            counter++;
            temp = temp->next;
        }

        // If the head node has to be deleted
        if (counter == n) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        int resultant = counter - n;
        temp = head;

        // Move to the node just before the one to delete
        while (resultant > 1) {
            temp = temp->next;
            resultant--;
        }

        // Delete the nth node from the end
        ListNode* delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode;

        return head;
    }
};