/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
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
    vector<int> mpreorder;
    vector<int> minorder;
public:
    TreeNode* builtTreeUtil(int& preIndex, int start, int end){
        if(start > end)
            return nullptr;
        
        TreeNode* root = new TreeNode(mpreorder[preIndex++]);
        if(start == end)
            return root;
        
        int index;
        for(index = start; index <= end; index++){
            if(minorder[index] == root->val)
                break;
        }
        
        root->left = builtTreeUtil(preIndex, start, index-1);
        root->right = builtTreeUtil(preIndex, index+1, end);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        mpreorder = move(preorder);
        minorder = move(inorder);
        int preIndex = 0;
        return builtTreeUtil(preIndex, 0, minorder.size()-1);
    }
};