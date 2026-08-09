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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* Curr = head;
        
        while(Curr!=NULL){
            ListNode* next = Curr->next;
            Curr->next=prev;
            prev = Curr;
            Curr = next;
        }
        return prev;
    }
};