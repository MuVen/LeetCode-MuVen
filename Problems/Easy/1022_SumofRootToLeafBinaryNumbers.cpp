/*
Given a binary tree, each node has value 0 or 1.  Each root-to-leaf path 
represents a binary number starting with the most significant bit.  
For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.

For all leaves in the tree, consider the numbers represented by the path from the root to that leaf.

Return the sum of these numbers.

 

Example 1:



Input: [1,0,1,0,1,0,1]
Output: 22
Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
 

Note:

The number of nodes in the tree is between 1 and 1000.
node.val is 0 or 1.
The answer will not exceed 2^31 - 1.
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
    vector<int> num;
    int sum;
public:
    int calcValue(){
        int val = 0;
        int one = 1;
        for(int i = num.size()-1, j = 0; i >= 0; i--, j++){
            val += ((one<<j)*num[i]);
        }
        return val;
    }

    void sumRootToLeafUtil(TreeNode* root){
        if(root == nullptr)
            return;
        
        num.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr){
            int val = calcValue();
            //cout<<val<<endl;
            sum += val;
            num.pop_back();
            return;
        }
        
        sumRootToLeafUtil(root->left);
        sumRootToLeafUtil(root->right);
        num.pop_back();
    }
    
    int sumRootToLeaf(TreeNode* root) {
        if(root == nullptr)
            return 0;

        sum = 0;
        sumRootToLeafUtil(root);
        return sum;
    }
};