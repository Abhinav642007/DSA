class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* smallHead = nullptr;
        ListNode* smallTail = nullptr;
        ListNode* largeHead = nullptr;
        ListNode* largeTail = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* temp = curr->next;
            curr->next = nullptr;

            if (curr->val < x) {
                if (smallHead == nullptr) {
                    smallHead = smallTail = curr;
                } else {
                    smallTail->next = curr;
                    smallTail = curr;
                }
            } else {
                if (largeHead == nullptr) {
                    largeHead = largeTail = curr;
                } else {
                    largeTail->next = curr;
                    largeTail = curr;
                }
            }

            curr = temp;
        }

        if (smallHead == nullptr)
            return largeHead;

        smallTail->next = largeHead;

        return smallHead;
    }
};