/*
Merge two sorted linked lists and return it as a new list. The new list 
should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if(l1 == nullptr && l2 != nullptr)
            return l2;
        
        if(l1 != nullptr && l2 == nullptr)
            return l1;
        
        if(l1 == nullptr && l2 == nullptr)
            return nullptr;
        
        ListNode* head = nullptr;
        ListNode* prev = nullptr;
        ListNode* n1 = nullptr;
        ListNode* n2 = nullptr;

        while(l1 && l2){
            if(l1->val == l2->val){
                n1 = l1;
                n2 = l2;
                l1 = l1->next;
                l2 = l2->next;
            }else if(l1->val > l2->val){
                n2 = l2;
                l2 = l2->next;
            }else {
                n1 = l1;
                l1 = l1->next;
            }
            
            if(n1 != nullptr && n2 != nullptr){
                    if(head == nullptr){
                        head = n1;
                        n1->next = n2;
                        prev = n2;
                    }
                    else
                    {
                        prev->next = n1;
                        n1->next = n2;
                        prev = n2;
                    }
                    n1 = n2 = nullptr;
            }else if(n1 == nullptr && n2 != nullptr){
                    if(head == nullptr){
                        head = n2;
                        prev = n2;
                    }else{
                        prev->next = n2;
                        prev = n2;
                    }
                    n2 = nullptr;
            }else if(n1 != nullptr && n2 == nullptr){
                if(head == nullptr){
                     head = n1;
                     prev = n1;
                }else{
                    prev->next = n1;
                    prev = n1;
                }
                n1 = nullptr;
            }
        }
        
        if(l1)
            prev->next = l1;
        if(l2)
            prev->next = l2;
        
        return head;
    }
};