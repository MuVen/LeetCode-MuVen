/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's 
sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:

[
   [5,4,11,2],
   [5,8,4,5]
]
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
    vector<vector<int>> res;
public:
    void pathSumUtil(TreeNode* root, vector<int> vec, int sum){
        if(root == nullptr)        
            return;
        
        if(root->left == nullptr && root->right == nullptr && sum == root->val){
            vec.push_back(sum);
            res.push_back(vec);
            return;
        }
        
        vec.push_back(root->val);
        pathSumUtil(root->left, vec, sum-root->val);
        pathSumUtil(root->right, vec, sum-root->val);
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root == nullptr)
            return res;

        vector<int> v;
        pathSumUtil(root, v, sum);
        return res;
    }
};