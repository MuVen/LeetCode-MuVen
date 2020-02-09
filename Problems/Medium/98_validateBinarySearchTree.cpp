/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:

    2
   / \
  1   3

Input: [2,1,3]
Output: true
Example 2:

    5
   / \
  1   4
     / \
    3   6

Input: [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
*/

//solution/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
typedef long long int lli;

class Solution {
public:
    bool isValidBSTUtil(TreeNode* root, lli min, lli max){
        if(root == nullptr)
            return true;
        
        if(root->val <= min || root->val >= max)
            return false;
        
        return isValidBSTUtil(root->left, min, root->val) && isValidBSTUtil(root->right, root->val, max);
    }

    bool isValidBST(TreeNode* root) {
        return isValidBSTUtil(root, LLONG_MIN, LLONG_MAX);
    }
};