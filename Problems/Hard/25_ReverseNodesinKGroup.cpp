/*
Given a linked list, reverse the nodes of a linked list k at a time and return
 its modified list.

k is a positive integer and is less than or equal to the length of the linked 
list. If the number of nodes is not a multiple of k then left-out nodes in the 
end should remain as it is.

Example:

Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

Note:

Only constant extra memory is allowed.
You may not alter the values in the list's nodes, only nodes itself may be 
changed.
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
    ListNode* reverse(ListNode* head, ListNode* last){
        
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        while(head != last){
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto node = head;
        for(int i = 0; i < k; ++i){
            if(!node)
                return head;
            node = node->next;
        }
        
        auto new_head = reverse(head, node);
        head->next = reverseKGroup(node, k);
        return new_head;
    }
};