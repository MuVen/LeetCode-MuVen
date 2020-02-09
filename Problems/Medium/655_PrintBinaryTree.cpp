/*
Print a binary tree in an m*n 2D string array following these rules:

The row number m should be equal to the height of the given binary tree.
The column number n should always be an odd number.
The root node's value (in string format) should be put in the exactly middle 
of the first row it can be put. The column and the row where the root node 
belongs will separate the rest space into two parts 
(left-bottom part and right-bottom part). You should print the left subtree 
in the left-bottom part and print the right subtree in the right-bottom part. 
The left-bottom part and the right-bottom part should have the same size. 
Even if one subtree is none while the other is not, you don't need to print 
anything for the none subtree but still need to leave the space as large as 
that for the other subtree. However, if two subtrees are none, then you don't
need to leave space for both of them.

Each unused space should contain an empty string "".
Print the subtrees following the same rules.
Example 1:
Input:
     1
    /
   2
Output:
[["", "1", ""],
 ["2", "", ""]]
Example 2:
Input:
     1
    / \
   2   3
    \
     4
Output:
[["", "", "", "1", "", "", ""],
 ["", "2", "", "", "", "3", ""],
 ["", "", "4", "", "", "", ""]]
Example 3:
Input:
      1
     / \
    2   5
   / 
  3 
 / 
4 
Output:

[["",  "",  "", "",  "", "", "", "1", "",  "",  "",  "",  "", "", ""]
 ["",  "",  "", "2", "", "", "", "",  "",  "",  "",  "5", "", "", ""]
 ["",  "3", "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]
 ["4", "",  "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]]
Note: The height of binary tree is in the range of [1, 10].
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
    vector<vector<string>> ans;
public:
    int getHeight(TreeNode* root){
        if(root == nullptr)
            return 0;
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        return max(left, right)+1;
    }
    int getWidth(TreeNode* root){
        if(root == nullptr)
            return 0;
        int left = getWidth(root->left);
        int right = getWidth(root->right);
        return max(left,right)*2+1;
    }
    void helper(TreeNode* root, int left, int right, int level){
        if(root == nullptr)
            return;
        
        int mid = left + (right - left)/2;
        ans[level][mid] = to_string(root->val);
        helper(root->left, left, mid-1, level+1);
        helper(root->right, mid+1, right, level+1);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        if(root == nullptr)
            return ans;
        
        int height = getHeight(root);
        int width = getWidth(root);   
        ans.resize(height, vector<string>(width,""));
        helper(root, 0, width-1, 0);
        return move(ans);
    }
};