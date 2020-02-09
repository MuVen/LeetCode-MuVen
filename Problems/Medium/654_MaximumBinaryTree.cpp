/*
Given an integer array with no duplicates. A maximum tree building on this 
array is defined as follow:

The root is the maximum number in the array.
The left subtree is the maximum tree constructed from left part subarray 
divided by the maximum number.
The right subtree is the maximum tree constructed from right part subarray 
divided by the maximum number.
Construct the maximum tree by the given array and output the root node of 
this tree.

Example 1:
Input: [3,2,1,6,0,5]
Output: return the tree root node representing the following tree:

      6
    /   \
   3     5
    \    / 
     2  0   
       \
        1
Note:
The size of the given array will be in the range [1,1000].
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
    vector<int> nu;
public:
    int max(int start, int end){
        int maxV = start;
        for(int i = start+1; i < end; i++){
            if(nu[i] > nu[maxV])
                maxV = i;
        }
        return maxV;
    }
    
    TreeNode* construct(int start, int end){
        if(start == end)
            return nullptr;

        int maxI = max(start, end);
        TreeNode* root = new TreeNode(nu[maxI]);
        root->left = construct(start, maxI);
        root->right = construct(maxI+1, end);
        return root;     
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size() == 0)
            return nullptr;

        nu = move(nums);
        return construct(0, nu.size());
    }
};