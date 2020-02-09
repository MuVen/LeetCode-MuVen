/*
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?
*/

//solution
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* thead;
public:
    
    void remove(int n){
        ListNode* temp = thead;
        ListNode* first = thead;
        while(n--){
            temp = temp->next;
        }
        ListNode* prev = nullptr;
        while(temp){
            prev = first;
            first = first->next;
            temp = temp->next;
        }
        if(temp == nullptr && prev == nullptr){
            thead = thead->next;
            return;
        }
        prev->next = first->next;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        thead = head;
        remove(n);
        return thead;
    }
};