/*
Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6
The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
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
    void post(TreeNode* root){
        if(root == nullptr)
            return;
        
        post(root->left);
        post(root->right);
        
        //flatten & concatinate root -> root->left -> root->right
        
        TreeNode* sright = root->right;
        if(root->left){
            root->right = root->left;
            root->left = nullptr;
            
            while(root->right)
                root = root->right;
            
            root->right = sright;
        }
    }
    
    void flatten(TreeNode* root) {
        if(root == nullptr)
            return;
        post(root);    
    }
};