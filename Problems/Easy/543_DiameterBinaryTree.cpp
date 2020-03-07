/*
Given a binary tree, you need to compute the length of the diameter of the tree.
 The diameter of a binary tree is the length of the longest path between any two
 nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them
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
#define MAX(a,b) ((a)>(b)?(a):(b))

class Solution {
    struct DH{
        int height;
        int diameter;
        DH(){
            height = diameter = 0;
        }
    };
public:
    DH getDiameter(TreeNode* root){
        if(root == nullptr)
            return DH();
        
        DH left = getDiameter(root->left);
        DH right = getDiameter(root->right);
        DH middle;
        middle.diameter = MAX(left.height+right.height+1, MAX(left.diameter, right.diameter));
        middle.height = MAX(left.height, right.height) + 1;
        return middle;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr)
            return 0;
        return getDiameter(root).diameter-1;
    }
};