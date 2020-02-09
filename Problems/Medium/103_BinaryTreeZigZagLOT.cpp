/*
Given a binary tree, return the zigzag level order traversal of its nodes' 
values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
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
    void zigzagLevelOrderUtil(TreeNode* root){
        if(root == nullptr)
            return;
        queue<TreeNode*> que;
        que.push(root);
        bool flag = false;
        vector<int> rtemp;
        stack<int> rstack;
        while(!que.empty()){
            int size = que.size();
            if(flag == false)
                rtemp.clear();

            while(size--){
                TreeNode* temp = que.front(); que.pop();
                if(temp->left)
                    que.push(temp->left);
                if(temp->right)
                    que.push(temp->right);
                if(flag == false)
                    rtemp.push_back(temp->val);
                else
                    rstack.push(temp->val);
            }
            
            if(flag == true){
                rtemp.clear();
                while(!rstack.empty()){
                    rtemp.push_back(rstack.top());
                    rstack.pop();
                }
            }
            
            res.push_back(rtemp);
            flag = !flag;
        }
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr)
            return res;

        zigzagLevelOrderUtil(root);
        return res;
    }
};