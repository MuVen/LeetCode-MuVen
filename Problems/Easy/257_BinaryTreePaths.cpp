/*
Given a binary tree, return all root-to-leaf paths.

Note: A leaf is a node with no children.

Example:

Input:

   1
 /   \
2     3
 \
  5

Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3
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
    vector<string> res;
public:
    void binaryTreePathsUtil(TreeNode* root, string s){
        if(root == nullptr)
            return;
        
        if(root->left == nullptr && root->right == nullptr){
            s += to_string(root->val);
            res.push_back(s);
            return;
        }

        s += to_string(root->val)+"->";
        binaryTreePathsUtil(root->left, s);
        binaryTreePathsUtil(root->right, s);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == nullptr)
            return vector<string>{};

        string s;
        binaryTreePathsUtil(root,s);
        return res;
    }
};