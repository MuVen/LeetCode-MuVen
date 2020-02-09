/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes,
 only nodes itself may be changed.

Example 1:

Given 1->2->3->4, reorder it to 1->4->2->3.
Example 2:

Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
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
    ListNode* middle(ListNode* head){
        if(head == nullptr)
            return nullptr;
        
        ListNode* rab = head;
        ListNode* hare = head;
        ListNode* prev = nullptr;
        while(hare && hare->next){
            prev = rab;
            rab = rab->next;
            hare = hare->next->next;
        }
        if(prev)
            prev->next = nullptr;
        return rab;
    }
    
    ListNode* reverse(ListNode* head){
        if(head == nullptr)
            return nullptr;
        
        ListNode* prev = nullptr;
        while(head){
            ListNode* temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        
        return prev;
    }
    
    void print(ListNode* node){
        if(node == nullptr)
            return;
        cout<<node->val<<" ";
        print(node->next);
    }
    
    void reorderList(ListNode* head) {
        if(head == nullptr)
            return;
        
        ListNode* middlem = middle(head);
        ListNode* rHead = reverse(middlem);        
        ListNode* prev = nullptr;
        while(head && rHead){
            ListNode* hnext = head->next;
            ListNode* rhnext = rHead->next;
            
            head->next = rHead;
            rHead->next = hnext;
            
            prev = rHead;
            
            head = hnext;
            rHead = rhnext;
        }
        
        if(rHead)
            prev->next = rHead;
    }
};