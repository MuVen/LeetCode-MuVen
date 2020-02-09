/*
Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> res;
public:
    void inorderUtil(TreeNode* root){
        if(root == nullptr)
            return;
        
        stack<TreeNode*> sta;
        TreeNode* curr = root;
        while(curr != nullptr || sta.empty() == false){
            while(curr){
                sta.push(curr);
                curr = curr->left;
            }
            
            TreeNode* temp= sta.top(); sta.pop();
            res.push_back(temp->val);
            
            curr = temp->right;
        }
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        inorderUtil(root);
        return move(res);
    }
};