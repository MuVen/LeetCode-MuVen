/*
Given a binary tree, return the postorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [3,2,1]
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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == nullptr)
            return vector<int>{};

        stack<TreeNode*> cur;
        stack<TreeNode*> out;
        cur.push(root);
        while(!cur.empty()){
            TreeNode* temp = cur.top();cur.pop();
            out.push(temp);
            if(temp->left)
                cur.push(temp->left);
            if(temp->right)
                cur.push(temp->right);
        }
        while(!out.empty()){
            res.push_back(out.top()->val);out.pop();
        }
        return move(res);
    }
};