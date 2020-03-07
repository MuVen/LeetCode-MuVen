/*
Given a binary search tree (BST) with duplicates, find all the mode(s) 
(the most frequently occurred element) in the given BST.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
 

For example:
Given BST [1,null,2,2],

   1
    \
     2
    /
   2
 

return [2].

Note: If a tree has more than one mode, you can return them in any order.

Follow up: Could you do that without using any extra space? 
(Assume that the implicit stack space incurred due to recursion does not count).
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
    TreeNode* prev = nullptr;
    int maxCount = INT_MIN;
    int count = 0;
    vector<int> ans;
public:
    void inorder(TreeNode* root, bool getList){
        if(root == nullptr)
            return;
        inorder(root->left, getList);
        if(prev && prev->val == root->val)
            count++;
        else
            count = 1;
        if(getList){
            if(count == maxCount)
                ans.push_back(root->val);
        }else{
            maxCount = max(maxCount, count);
        }
        prev = root;
        inorder(root->right, getList);
    }

    vector<int> findMode(TreeNode* root) {
        inorder(root, false);
        cout<<maxCount<<endl;
        count = 0; prev = nullptr;
        inorder(root, true);
        return ans;
    }
};