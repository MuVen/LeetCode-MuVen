/*
Given a binary tree, return the vertical order traversal of its nodes values.

For each node at position (X, Y), its left and right children
 respectively will be at positions (X-1, Y-1) and (X+1, Y-1).

Running a vertical line from X = -infinity to X = +infinity, 
whenever the vertical line touches some nodes, we report the values of the 
nodes in order from top to bottom (decreasing Y coordinates).

If two nodes have the same position, then the value of the node that is
 reported first is the value that is smaller.

Return an list of non-empty reports in order of X coordinate.  
Every report will have a list of values of nodes.

 

Example 1:
Input: [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Explanation: 
Without loss of generality, we can assume the root node is at position (0, 0):
Then, the node with value 9 occurs at position (-1, -1);
The nodes with values 3 and 15 occur at positions (0, 0) and (0, -2);
The node with value 20 occurs at position (1, -1);
The node with value 7 occurs at position (2, -2).

Example 2:
Input: [1,2,3,4,5,6,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation: 
The node with value 5 and the node with value 6 have the same position according to the given scheme.
However, in the report "[1,5,6]", the node value of 5 comes first since 5 is smaller than 6.
 
Note:

The tree will have between 1 and 1000 nodes.
Each node's value will be between 0 and 1000.
*/

//solution
#define MIN(a,b) ((a)>(b)?(b):(a))
#define MAX(a,b) ((a)>(b)?(a):(b))
typedef pair<int, int> mypair;

class Solution {
	unordered_map<int, vector<mypair>> map;
	int minhd = INT_MAX;
	int maxhd = INT_MIN;
public:
	void vertical(TreeNode* root, int vd, int hd){
		if (root == nullptr)
			return;

		minhd = MIN(minhd, hd);
		maxhd = MAX(maxhd, hd);

		auto& second = map[hd];
		second.push_back({ vd, root->val });

		vertical(root->left, vd + 1, hd - 1);
		vertical(root->right, vd + 1, hd + 1);
	}

	vector<vector<int>> verticalTraversal(TreeNode* root) {
		vector<vector<int>> res;
		if (root == nullptr)
			return res;

		vertical(root, 0, 0);
		for (int i = minhd; i <= maxhd; i++){
			vector<int> tres;
			auto& second = map[i];
			sort(second.begin(), second.end(), [](const mypair& a, const mypair& b){ 
				if (a.first != b.first)
					return a.first < b.first;
				return a.second < b.second;
			});
			for (int i = 0; i < second.size(); i++){
				tres.push_back(second[i].second);
			}
			res.push_back(tres);
		}

		return res;
	}
};