/*
The thief has found himself a new place for his thievery again.
 is only one entrance to this area, called the "root." Besides the root, 
 each house has one and only one parent house. After a tour, the smart thief 
 realized that "all houses in this place forms a binary tree". 
 It will automatically contact the police if two directly-linked houses
 were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without 
alerting the police.

Example 1:

Input: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \ 
     3   1

Output: 7 
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:

Input: [3,4,5,1,3,null,1]

     3
    / \
   4   5
  / \   \ 
 1   3   1

Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
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
static inline int MAX(int a, int b){
    return a > b ? a : b;
}
class Solution {
    //unordered_map<TreeNode*, int> map;
public:
    vector<int> robU(TreeNode* root){
        vector<int> vec(2,0);
        if(root == nullptr)
            return vec;
        
        vector<int> left = robU(root->left);
        vector<int> right = robU(root->right);
        
        vec[0] = root->val + left[1] + right[1];
        vec[1] = MAX(left[0], left[1]) + MAX(right[0], right[1]);
        return vec;
    }
    
    int rob(TreeNode* root) {
        if(root == nullptr)
            return 0;

        vector<int> res = robU(root);
        return MAX(res[0], res[1]);
    }
};