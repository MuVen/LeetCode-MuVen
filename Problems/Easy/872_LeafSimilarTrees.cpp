/*
Consider all the leaves of a binary tree.  From left to right order,
the values of those leaves form a leaf value sequence.



For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.

 

Note:

Both of the given trees will have between 1 and 100 nodes.
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
    string l1;
    string l2;
public:
    void pot(TreeNode* root1, string& v){
        if(root1 == nullptr)
            return;
        
        if(root1->left == nullptr && root1->right == nullptr)
            v+=to_string(root1->val);

        pot(root1->left,v);
        pot(root1->right,v);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr && root2 == nullptr)
            return true;

        pot(root1,l1);
        pot(root2,l2);
        
        return l1 == l2;
    }
};