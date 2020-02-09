/*
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order and each of their nodes contain a 
single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, 
except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr && l1 == nullptr)return nullptr;
        if(l1 == nullptr)return l2;
        if(l2 == nullptr)return l1;
        ListNode* head = l1;
        ListNode* prev = nullptr;
        int carry = 0;
        while(l1 && l2){
            int sum = l1->val + l2->val + carry;
            if(carry == 1)
                carry = 0;
            if(sum >= 10){
                carry = 1;
                sum = sum %10;
            }
            
            l1->val = sum;
            
            prev = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        if(l1 == nullptr && l2 == nullptr){
            if(carry)
                prev->next = new ListNode(1);
            return head;
        }
        
        if(l1){
            while(l1){
                int sum = l1->val + carry;
                if(carry == 1)
                    carry = 0;
                if(sum >= 10){
                    carry = 1;
                    sum = sum%10;
                }
                l1->val = sum;
                prev = l1;
                l1 = l1->next;
            }
            if(carry)
               prev->next = new ListNode(1);
            return head;
        }
        
        while(l2){
                int sum = l2->val + carry;
                if(carry == 1)
                    carry = 0;
                if(sum >= 10){
                    carry = 1;
                    sum = sum%10;
                }
                prev->next = new ListNode(sum);
                prev = prev->next;
                l2 = l2->next;
        }
        if(carry)
           prev->next = new ListNode(1);
        return head;
    }
};