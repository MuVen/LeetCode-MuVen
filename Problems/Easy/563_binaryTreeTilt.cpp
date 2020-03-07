/*
Given a binary tree, return the tilt of the whole tree.

The tilt of a tree node is defined as the absolute difference between the
 sum of all left subtree node values and the sum of all right subtree node
 values. Null node has tilt 0.

The tilt of the whole tree is defined as the sum of all nodes' tilt.

Example:
Input: 
         1
       /   \
      2     3
Output: 1
Explanation: 
Tilt of node 2 : 0
Tilt of node 3 : 0
Tilt of node 1 : |2-3| = 1
Tilt of binary tree : 0 + 0 + 1 = 1
Note:

The sum of node values in any subtree won't exceed the range of 32-bit integer.
All the tilt values won't exceed the range of 32-bit integer.
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
int abs(int a, int b){
    return a > b ? a - b : b - a;
}
class Solution {
    int tilt = 0;
public:
    int findTiltUtil(TreeNode* root){
        if(root == nullptr)
            return 0;
        
        int ltilt = findTiltUtil(root->left);
        int rtilt = findTiltUtil(root->right);
        tilt += abs(ltilt, rtilt);
        cout<<ltilt<<" "<<rtilt<<" "<<root->val<<" "<<ltilt + rtilt + root->val<<endl;
        return ltilt + rtilt + root->val;
    }
    
    int findTilt(TreeNode* root) {
        if(root == nullptr)
            return 0;
        findTiltUtil(root);
        return tilt;
    }
};