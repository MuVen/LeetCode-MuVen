Given a binary tree, find the leftmost value in the last row of the tree.

Example 1:
Input:

    2
   / \
  1   3

Output:
1
Example 2:
Input:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

Output:
7
Note: You may assume the tree (i.e., the given root node) is not NULL.
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
    int dleftvalue;
public:
    void findBottomLeftValueUtil(TreeNode* root, int& currlevel, int level){
        if(root == nullptr)
            return;
        
        if(level > currlevel){
            currlevel = level;
            dleftvalue = root->val;
        }
        
        findBottomLeftValueUtil(root->left, currlevel, level+1);
        findBottomLeftValueUtil(root->right, currlevel, level+1);
    }
    
    int findBottomLeftValue(TreeNode* root) {
        int currlevel = 0;
        findBottomLeftValueUtil(root, currlevel, 1);
        return dleftvalue;
    }
};