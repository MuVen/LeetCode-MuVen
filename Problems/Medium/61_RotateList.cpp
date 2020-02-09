/*
Given a linked list, rotate the list to the right by k places, 
where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
Example 2:

Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL
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
    ListNode* lnode;
    ListNode* lknode;
    ListNode* anode;
public:
    int length(){
        int count = 0;
        ListNode* htemp = thead;
        while(htemp){
            count++;
            if(htemp->next == nullptr)
                lnode = htemp;
            htemp = htemp->next;
        }
        return count;
    }
    
    void process(int k){
        ListNode* ftemp = thead;
        ListNode* fnode = thead;
        ListNode* prev = nullptr;
        while(k--){
            ftemp = ftemp->next;
        }
        while(ftemp){
            prev = fnode;
            fnode = fnode->next;
            ftemp = ftemp->next;
        }
        
        anode = prev->next;
        prev->next = nullptr;
        lnode->next = thead;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 || head == nullptr)
            return head;
        thead = head;
        int len = length();
        k = k % len;
        if(k == 0)
            return head;
        process(k);
        return anode;
    }
};