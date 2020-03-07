/*
In a binary tree, the root node is at depth 0, and children of each 
depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, 
but have different parents.

We are given the root of a binary tree with unique values, and the 
values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the 
values x and y are cousins.

 

Example 1:


Input: root = [1,2,3,4], x = 4, y = 3
Output: false
Example 2:


Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
Example 3:



Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
 

Note:

The number of nodes in the tree will be between 2 and 100.
Each node has a unique integer value from 1 to 100.
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
    void distance(TreeNode* root, int x, int d, bool& found, int& fd){
        if(root == nullptr)
            return;
        
        if(root->val == x){
            found = true;
            fd = d;
            return;
        }
        
        if(found)
            return;

        distance(root->left, x, d+1, found, fd);
        distance(root->right, x, d+1, found, fd);
    }

    bool issibiling(TreeNode* root, int x, int y){
        if(root == nullptr)
            return false;
        
        if(root->left && root->right){
            if(root->left->val == x && root->right->val == y)
                return true;
            if(root->left->val == y && root->right->val == x)
                return true;
        }
        
        return issibiling(root->left, x, y) || issibiling(root->right, x, y);
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        int fd1, fd2;
        bool found = false;
        distance(root, x, 1, found, fd1);
        found = false;
        distance(root, y, 1, found, fd2);
        cout<<fd1<<" "<<fd2<<endl;
        if(fd1 != fd2)
            return false;
        
        bool issiblings = issibiling(root, x, y);
        cout<<"issiblings:"<<issiblings<<endl;
        if(issiblings)
            return false;
        
        return true;
    }
};