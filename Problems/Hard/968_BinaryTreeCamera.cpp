/*
Given a binary tree, we install cameras on the nodes of the tree. 

Each camera at a node can monitor its parent, itself, and its immediate children.

Calculate the minimum number of cameras needed to monitor all nodes of the tree.

 

Example 1:
	

Input: [0,0,null,0,0]
Output: 1
Explanation: One camera is enough to monitor all nodes if placed as shown.
Example 2:


Input: [0,0,null,0,null,0,null,null,0]
Output: 2
Explanation: At least two cameras are needed to monitor all nodes of the tree. 
The above image shows one of the valid configurations of camera placement.

Note:

The number of nodes in the given tree will be in the range [1, 1000].
Every node has value 0.
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
    int NOT_MONITORED = 0;
    int HAS_CAMERA = 1;
    int MONITORED_BY_OTHER = 2;
    int count = 0;
public:
    int minCameraCoverUtil(TreeNode* root){
        if(root == nullptr)
            return MONITORED_BY_OTHER;
        
        int left = minCameraCoverUtil(root->left);
        int right = minCameraCoverUtil(root->right);
        
        if(left == NOT_MONITORED || right == NOT_MONITORED){
            count++;
            return HAS_CAMERA;
        }
        
        if(left == HAS_CAMERA || right == HAS_CAMERA){
            return MONITORED_BY_OTHER;
        }
        
        return NOT_MONITORED;
    }
    
    int minCameraCover(TreeNode* root) {
        if(minCameraCoverUtil(root) == NOT_MONITORED)
            count++;
        return count;
    }
};