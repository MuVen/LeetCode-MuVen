/*
Given a binary tree

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next 
right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

 

Follow up:

You may only use constant extra space.
Recursive approach is fine, you may assume implicit stack space does not count 
as extra space for this problem.
 

Example 1:



Input: root = [1,2,3,4,5,null,7]
Output: [1,#,2,3,#,4,5,7,#]
Explanation: Given the above binary tree (Figure A), your function should 
populate each next pointer to point to its next right node, just like in Figure B.
 The serialized output is in level order as connected by the next pointers, 
 with '#' signifying the end of each level.
 

Constraints:

The number of nodes in the given tree is less than 6000.
-100 <= node.val <= 100
*/

//solution
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
	void connectUtil(Node* root){
		queue<Node*> que;
		que.push(root);
		while (!que.empty()){
			stack<Node*> sta;
			int size = que.size();
			while (size--){
				Node* temp = que.front(); que.pop();
				sta.push(temp);
				if (temp->left)
					que.push(temp->left);
				if (temp->right)
					que.push(temp->right);
			}

			Node* next = nullptr;
			while (!sta.empty()){
				Node* curr = sta.top(); sta.pop();
				curr->next = next;
				next = curr;
			}
		}
	}

	Node* connect(Node* root) {
        if(root == nullptr)
            return nullptr;
            
		connectUtil(root);
		return root;
	}
};