/*
Given a binary search tree, write a function kthSmallest to 
find the kth smallest element in it.

Note:
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Example 1:

Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1
Example 2:

Input: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
Output: 3
Follow up:
What if the BST is modified (insert/delete operations) often and you need to 
find the kth smallest frequently? How would you optimize the kthSmallest routine?
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
    bool found = false;
    int ans;
public:
    void inorder(TreeNode* root, int& k, int& K){
        if(root == nullptr)
            return;
        
        if(found == true)
            return;
        
        inorder(root->left, k, K);
        k++;
        if(k == K){
            found = true;
            ans = root->val;
            return;
        }
        inorder(root->right, k, K);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int c = 0;
        inorder(root, c, k);
        return ans;
    }
};