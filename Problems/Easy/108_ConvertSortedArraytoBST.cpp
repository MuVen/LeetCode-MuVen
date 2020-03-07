/*
Given an array where elements are sorted in ascending order, convert it to a 
height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in 
which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted array: [-10,-3,0,5,9],

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
	vector<int> arr;
public:
	TreeNode* convert(int start, int end){
		if (start > end)
			return nullptr;
		int mid = (start + end) / 2;
		TreeNode* root = new TreeNode(arr[mid]);
		root->left = convert(start, mid - 1);
		root->right = convert(mid + 1, end);
		return root;
	}

	TreeNode* sortedArrayToBST(vector<int>& nums) {
		arr = move(nums);
		TreeNode* root = convert(0, arr.size() - 1);
		return root;
	}
};