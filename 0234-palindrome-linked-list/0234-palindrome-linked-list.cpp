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

    // Reverse function
    ListNode* reverse(ListNode* head){
    //     ListNode* prev = NULL;
    //     ListNode* curr = head;

    //     while(curr != NULL){
    //         ListNode* next = curr->next;
    //         curr->next = prev;
    //         prev = curr;
    //         curr = next;
    //     }

    //     return prev;
    // }

    // bool isPalindrome(ListNode* head) {

    //     // Empty list ya single node
    //     if(head == NULL || head->next == NULL)
    //         return true;

    //     // Step 1: Find middle
    //     ListNode* slow = head;
    //     ListNode* fast = head;

    //     while(fast->next->next != NULL && fast->next != NULL){
    //         slow = slow->next;
    //         fast = fast->next->next;
    //     }

    //     // // Step 2: Reverse second half
    //     // ListNode* second = reverse(slow);

    //     // // Step 3: Compare
    //     // ListNode* first = head;

    //     // while(second != NULL){
    //     //     if(first->val != second->val)
    //     //         return false;

    //     //     first = first->next;
    //     //     second = second->next;
    //     // }

    //     // return true;
    //     ListNode* newhead = reverse(slow->next);
    //     ListNode* first = head;
    //     ListNode* second = newhead;

    //     while(second!=NULL){
    //         if(first->val!=second->val){
    //             reverse(newhead);
    //             return false;
    //         }
    //         first=first->next;
    //         second= second->next;
    //     }
    //     reverse(newhead);
    //     return true;
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr!=NULL){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;

    }
    bool isPalindrome(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* newhead = reverse(slow->next);
        ListNode* first=head;
        ListNode* second= newhead;

        while(second!=NULL){
            if(first->val!=second->val){
                reverse(newhead);
                return false;

            }
            first=first->next;
            second=second->next;
        }
        reverse(newhead);
        return true;

    }
};