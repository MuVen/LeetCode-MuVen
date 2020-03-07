/*
Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?
*/

//solution
class Solution {
public:
	inline ListNode* reverse(ListNode* head){
		ListNode* prev = nullptr;
		while (head){
			ListNode* ntext = head->next;
			head->next = prev;
			prev = head;
			head = ntext;
		}
		return prev;
	}
	inline ListNode* middleNode(ListNode* head){
		ListNode* p1 = head;
		ListNode* p2 = head;
		while (p2 && p2->next){
			p1 = p1->next;
			p2 = p2->next->next;
		}
		return p1;
	}
	inline int length(ListNode* head){
		if (head == nullptr)return 0;
		int count = 0;
		while (head){
			count++;
			head = head->next;
		}
		return count;
	}
	bool isPalindrome(ListNode* head) {
		int len = length(head);
		
		ListNode* middle = middleNode(head);
		if (len % 2 != 0)
			middle = middle->next;

		ListNode* rlist = reverse(middle);

		while (rlist && head){
			if (rlist->val != head->val)
				return false;
			rlist = rlist->next;
			head = head->next;
		}
		return true;
	}
};