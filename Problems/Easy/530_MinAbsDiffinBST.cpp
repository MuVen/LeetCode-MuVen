/*
Given a binary search tree with non-negative values, find the 
minimum absolute difference between values of any two nodes.

Example:

Input:

   1
    \
     3
    /
   2

Output:
1

Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
 

Note:

There are at least two nodes in this BST.
This question is the same as 783: https://leetcode.com/problems/minimum-distance-between-bst-nodes/
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

int min(int a, int b){
    return a>b?b:a;
}

int absm(int a, int b){
    return a > b ? a -b : b - a;
}

class Solution {
    int ans = INT_MAX;
    TreeNode* prev = nullptr;
public:
    void getMinimumDifferenceUtil(TreeNode* root) {
        if(root == nullptr)
            return;
        
        getMinimumDifferenceUtil(root->left);
        ans = min(absm(prev ? prev->val : INT_MAX, root ? root->val : INT_MAX), ans);
        prev = root;
        getMinimumDifferenceUtil(root->right);
    }
    
    int getMinimumDifference(TreeNode* root) {
        if(root == nullptr)
            return INT_MAX;

        getMinimumDifferenceUtil(root);
        return ans;
    }
};