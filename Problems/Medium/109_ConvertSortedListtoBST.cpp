/*
Given a singly linked list where elements are sorted in ascending order, 
convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in 
which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted linked list: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following 
height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
*/

//solution
class Solution {
public:
	int len(ListNode* head){
		int count = 0;
		while (head){
			count++;
			head = head->next;
		}
		return count;
	}

	TreeNode* sortedListToBSTUtil(ListNode** head, int len){
		if (len <= 0)
			return nullptr;

		TreeNode* left = sortedListToBSTUtil(head, len / 2);
		TreeNode* root = new TreeNode((*head)->val);
		(*head) = (*head)->next;
		root->left = left;
		root->right = sortedListToBSTUtil(head, len - len / 2 - 1);
		return root;
	}

	TreeNode* sortedListToBST(ListNode* head) {
		if (head == nullptr)
			return nullptr;

		int length = len(head);
		return sortedListToBSTUtil(&head, length);
	}
};