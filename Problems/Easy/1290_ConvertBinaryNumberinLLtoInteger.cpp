/*
Given head which is a reference node to a singly-linked list. 
The value of each node in the linked list is either 0 or 1.
 The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.

 

Example 1:


Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10
Example 2:

Input: head = [0]
Output: 0
Example 3:

Input: head = [1]
Output: 1
Example 4:

Input: head = [1,0,0,1,0,0,1,1,1,0,0,0,0,0,0]
Output: 18880
Example 5:

Input: head = [0,0]
Output: 0
 

Constraints:

The Linked List is not empty.
Number of nodes will not exceed 30.
Each node's value is either 0 or 1.
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
    int getDecimalValue(ListNode* head) {
        if(head == nullptr)
            return 0;
        vector<int> bin;
        while(head){
            bin.push_back(head->val);
            head = head->next;
        }
        
        int num = 0;
        for(int i = bin.size()-1, j = 0 ; i >= 0; i--, j++){
            num +=  bin[i]*(1<<j);
        }
        
        return num;
    }
};