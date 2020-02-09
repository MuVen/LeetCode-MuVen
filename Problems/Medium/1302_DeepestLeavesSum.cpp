/*
Given a binary tree, return the sum of values of its deepest leaves.
 

Example 1:
Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
Output: 15
 

Constraints:

The number of nodes in the tree is between 1 and 10^4.
The value of nodes is between 1 and 100.
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
    struct node{
        TreeNode* root;
        int level;
    };
public:
    int deepestLeavesSum(TreeNode* root) {
        if(root == nullptr)
            return 0;
        
        unordered_map<int, int> map;
        int maxLevel = 1;
        queue<node> que;
        que.push({root,1});
        while(!que.empty()){
            node n = que.front();que.pop();
            map[n.level] += n.root->val;
            maxLevel = max(maxLevel, n.level);
            if(n.root->left)
                que.push({n.root->left, n.level+1});
            if(n.root->right)
                que.push({n.root->right, n.level+1});
        }
        
        return map[maxLevel];
    }
};