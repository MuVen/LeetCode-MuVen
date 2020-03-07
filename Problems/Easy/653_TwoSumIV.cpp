/*
Given a Binary Search Tree and a target number, return true if there exist 
two elements in the BST such that their sum is equal to the given target.

Example 1:

Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9

Output: True
 

Example 2:

Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28

Output: False
 
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
int abs(int& a, int& b){
    return a > b ? a-b : b-a;
}
class Solution {
    unordered_set<int> set;
public:
         
    bool findTarget(TreeNode* root, int k) { 
        if(root == nullptr)
            return false;
        
        if(set.find(k-root->val) != set.end())
            return true;
        
        set.insert(root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
};