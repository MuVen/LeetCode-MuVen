/*
Given a binary tree, write a function to get the maximum width of the given tree.
 The width of a tree is the maximum width among all levels. 
 The binary tree has the same structure as a full binary tree,
 but some nodes are null.

The width of one level is defined as the length between the end-nodes 
(the leftmost and right most non-null nodes in the level, where the null nodes 
between the end-nodes are also counted into the length calculation.

Example 1:

Input: 

           1
         /   \
        3     2
       / \     \  
      5   3     9 

Output: 4
Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).
Example 2:

Input: 

          1
         /  
        3    
       / \       
      5   3     

Output: 2
Explanation: The maximum width existing in the third level with the length 2 (5,3).
Example 3:

Input: 

          1
         / \
        3   2 
       /        
      5      

Output: 2
Explanation: The maximum width existing in the second level with the length 2 (3,2).
Example 4:

Input: 

          1
         / \
        3   2
       /     \  
      5       9 
     /         \
    6           7
Output: 8
Explanation:The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).


Note: Answer will in the range of 32-bit signed integer.
*/
//solution
#define min(a,b) ((a)>(b)?(b):(a))
#define max(a,b) ((a)>(b)?(a):(b))
#define abs(a,b) ((a)>(b)?((a)-(b)):((b)-(a)))
typedef unsigned long long int ulli;
class Solution {
public:
	int widthOfBinaryTree(TreeNode* root) {
		if (root == nullptr)
			return 0;
		queue<TreeNode*> que;
		queue<ulli> qval;
		que.push(root);
		qval.push(0);
		ulli ans = 0;
		while (!que.empty()) {
			int size = que.size();
			ulli minv = UINT64_MAX;
			ulli maxv = 0;
			while (size--) {
				TreeNode* n = que.front(); que.pop();
				ulli index = qval.front(); qval.pop();
				if (n) {
					if (n->left) {
						que.push(n->left);
						qval.push(index * 2 + 1);
					}
					if (n->right) {
						que.push(n->right);
						qval.push(index * 2 + 2);
					}
				}
				minv = min(index, minv);
				maxv = max(index, maxv);
			}
			ans = max(abs(maxv, minv), ans);
		}
		return ans + 1;
	}
};