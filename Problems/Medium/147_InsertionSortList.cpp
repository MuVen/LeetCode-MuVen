/*
Sort a linked list using insertion sort.


A graphical example of insertion sort. The partial sorted list (black) initially
contains only the first element in the list.
With each iteration one element (red) is removed from the input data and inserted
 in-place into the sorted list
 

Algorithm of Insertion Sort:

Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
At each iteration, insertion sort removes one element from the input data, 
finds the location it belongs within the sorted list, and inserts it there.
It repeats until no input elements remain.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5
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
    ListNode* first = nullptr;
    ListNode* last = nullptr;
public:
    void insert(ListNode* node){
        if(first == nullptr && last == nullptr){
            first = last = node;
            return;
        }
        
        if(first == last){
            if(node->val > first->val){
                first->next = node;
                last = node;
            }else{
                node->next = first;
                first = node;
            }
            return;
        }
        
        ListNode* prev = nullptr;
        ListNode* ftemp = first;
        while(ftemp){
            if(node->val < ftemp->val)
                break;
            prev = ftemp;
            ftemp = ftemp->next;
        }
        
        if(prev == nullptr && ftemp == first){
            node->next = first;
            first = node;
            return;
        }
        
        node->next = prev->next;
        prev->next = node;
    }
    
    ListNode* insertionSortList(ListNode* head) {
        ListNode* next;
        while(head){
            next = head->next;
            head->next = nullptr;
            insert(head);
            head = next;
        }
        return first;
    }
};