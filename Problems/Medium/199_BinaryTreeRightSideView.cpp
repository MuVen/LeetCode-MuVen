/*
Given a binary tree, imagine yourself standing on the right side of it, 
return the values of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
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
    vector<int> result;
public:
    void rightSide(TreeNode* root, int& currLevel, int level){
        if(root == nullptr)
            return;
        
        if(level > currLevel){
            result.push_back(root->val);
            currLevel = level;
        }
        rightSide(root->right, currLevel, level+1);
        rightSide(root->left, currLevel, level+1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        int currLevel = 0;
        rightSide(root, currLevel, 1);
        return move(result);
    }
};