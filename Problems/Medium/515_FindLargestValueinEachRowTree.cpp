/*
You need to find the largest value in each row of a binary tree.

Example:
Input: 

          1
         / \
        3   2
       / \   \  
      5   3   9 

Output: [1, 3, 9]
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
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if(root == nullptr)
            return res;

        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int size = que.size();
            int max = INT_MIN;
            while(size--){
                TreeNode* temp = que.front(); que.pop();
                if(temp->left)
                    que.push(temp->left);
                if(temp->right)
                    que.push(temp->right);
                max = MAX(max, temp->val);
            }
            res.push_back(max);
        }
        return res;
    }
};