/*
Given a Binary Search Tree (BST), convert it to a Greater Tree such that every
 key of the original BST is changed to the original key plus sum of all keys 
 greater than the original key in BST.

Example:

Input: The root of a Binary Search Tree like this:
              5
            /   \
           2     13

Output: The root of a Greater Tree like this:
             18
            /   \
          20     13
Note: This question is the same as 1038: 
https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/
*/

//solution
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void converBSTUtil(TreeNode* root, int& sum){
        if(root == nullptr)
            return;
        
        converBSTUtil(root->right, sum);   
        sum += root->val;
        root->val = sum;
        converBSTUtil(root->left, sum);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        converBSTUtil(root, sum);
        return root; 
    }
};