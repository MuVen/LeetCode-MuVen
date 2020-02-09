/*
Given a sorted linked list, delete all nodes that have duplicate numbers, 
leaving only distinct numbers from the original list.

Example 1:

Input: 1->2->3->3->4->4->5
Output: 1->2->5
Example 2:

Input: 1->1->1->2->3
Output: 2->3
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
    ListNode* anshead;
    ListNode* ans;
    ListNode* thead;
public:
    ListNode* getNonDuplicate(ListNode* head){
        if(head == nullptr)
            return nullptr;
        
        //if current node and next node not equal then 
        //add current node to ans and return next node;
        if(head && head->next && head->val != head->next->val){
            ListNode* rnode = head->next;
            head->next = nullptr;
            if(ans == nullptr){
                ans = head;
                anshead = head;
            }else{
                ans->next = head;
                ans = head;
            }
            return rnode;
        }
        //if current node and next node is not equal to null then
        //add the current node to ans and return nullptr;
        else if(head && head->next == nullptr){
            if(ans == nullptr){
                ans = head;
                anshead = head;
            }else{
                ans->next = head;
                ans = head;    
            }
            return nullptr;
        }
        //if current node and next node is equal then
        //return the node bypassing all the equal nodes;
        else {
            int val = head->val;
            while(head){
                if(head->val != val){
                    return head;
                }
                head = head->next;
            }
        }
        return nullptr;
    }
    
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr)
            return nullptr;
        
        thead = head;
        while(thead)
            thead = getNonDuplicate(thead);
        return anshead;
    }
};