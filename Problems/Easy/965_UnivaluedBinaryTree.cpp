/*
A binary tree is univalued if every node in the tree has the same value.

Return true if and only if the given tree is univalued.

 

Example 1:


Input: [1,1,1,1,1,null,1]
Output: true
Example 2:


Input: [2,2,2,5,2]
Output: false
 

Note:

The number of nodes in the given tree will be in the range [1, 100].
Each node's value will be an integer in the range [0, 99].
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
    bool isUniValid(TreeNode* root, int& val){
        if(root == nullptr)
            return true;
        
        if(root->val != val)
            return false;
        
        return isUniValid(root->left, val) && isUniValid(root->right, val);
    }
    
    bool isUnivalTree(TreeNode* root) {
        if(root == nullptr)
            return true;
        
        int val = root->val;
        return isUniValid(root, val);
    }
};