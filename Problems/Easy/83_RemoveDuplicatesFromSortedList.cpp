/*
Given a sorted linked list, delete all duplicates such that each 
element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2
Example 2:

Input: 1->1->2->3->3
Output: 1->2->3
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
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr)
            return nullptr;

        ListNode* thead = head;
        ListNode* fhead = thead;
        ListNode* prev = fhead;
        while(fhead){
            if(fhead->val != prev->val){
                prev->next = fhead;
                prev = fhead;
            }
            fhead = fhead->next;
        }
        prev->next = nullptr;
        return thead;
    }
};