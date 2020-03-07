/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the 
root node down to the nearest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its minimum depth = 2.
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
    
    void minDepthUtil(TreeNode* root, int level, int& minlevel){
        if(root == nullptr)
            return;
        
        if(level > minlevel)
            return;
        
        if(root->left == nullptr && root->right == nullptr){
            if(level < minlevel)
                minlevel = level;
        }
        
        minDepthUtil(root->left, level+1, minlevel);
        minDepthUtil(root->right, level+1, minlevel);
    }
    
    int minDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        
        if(root->left == nullptr && root->right == nullptr)
            return 1;
        
        int minlevel = INT_MAX;
        minDepthUtil(root, 1, minlevel);
        return minlevel;
    }
};