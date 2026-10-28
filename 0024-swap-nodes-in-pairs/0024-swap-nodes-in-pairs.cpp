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
    ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next)
        return head;

    // Dummy node before the head
    ListNode* dummyNode = new ListNode();

    ListNode* prevNode = dummyNode;
    ListNode* currNode = head;

    while (currNode && currNode->next) {
        // 1. Connect previous node to second node
        prevNode->next = currNode->next;

        // 2. Connect first node to the node after the pair
        currNode->next = prevNode->next->next;

        // 3. Connect second node back to first node
        prevNode->next->next = currNode;

        // Move to the next pair
        prevNode = currNode;
        currNode = currNode->next;
    }

    return dummyNode->next;
}
};