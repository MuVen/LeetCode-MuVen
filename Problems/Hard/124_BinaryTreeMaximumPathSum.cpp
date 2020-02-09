/*
Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting
node to any node in the tree along the parent-child connections. 
The path must contain at least one node and does not need to go through the 
root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6
Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42
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
#define MAX(a,b) ((a)>(b)?(a):(b))
class Solution {
public:
    int maxPathSumUtil(TreeNode* root, int& ans){
        if(root == nullptr)
            return 0;
        
        int left = maxPathSumUtil(root->left, ans);
        int right = maxPathSumUtil(root->right, ans);
        
        if(left < 0)
            left = 0;
        if(right < 0)
            right = 0;

        ans = MAX(ans, left+right+root->val);        
        return root->val + MAX(left, right);
    }
    
    int maxPathSum(TreeNode* root) {
        if(root == nullptr)
            return INT_MIN;

        int max = INT_MIN;
        maxPathSumUtil(root, max);
        return max;
    }
};