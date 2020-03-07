/*
Given a binary tree, find the length of the longest path where each node
 in the path has the same value. This path may or may not pass through the root.

The length of path between two nodes is represented by the number of edges between them.

 

Example 1:

Input:

              5
             / \
            4   5
           / \   \
          1   1   5
Output: 2

 

Example 2:

Input:

              1
             / \
            4   5
           / \   \
          4   4   5
Output: 2

 

Note: The given binary tree has not more than 10000 nodes.
 The height of the tree is not more than 1000.
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
    int traversalPath(TreeNode* root, int& maxPath){
        if(root == nullptr)
            return 0;
        
        int left = traversalPath(root->left, maxPath);
        int right = traversalPath(root->right, maxPath);
        
        left = (root->left && (root->left->val == root->val)) ? left + 1 : 0;
        right = (root->right && (root->right->val == root->val)) ? right + 1 : 0;
        maxPath = MAX(maxPath, left+right);
        return MAX(left, right);
    }
    
    int longestUnivaluePath(TreeNode* root) {
        if(root == nullptr)
            return 0;

        int maxPath = INT_MIN;
        traversalPath(root, maxPath);
        return maxPath;
    }
};