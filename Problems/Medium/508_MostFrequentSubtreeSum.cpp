/*
Given the root of a tree, you are asked to find the most frequent subtree sum.
 The subtree sum of a node is defined as the sum of all the node values formed 
 by the subtree rooted at that node (including the node itself). 
 So what is the most frequent subtree sum value? 
 If there is a tie, return all the values with the highest frequency in any order.

Examples 1
Input:

  5
 /  \
2   -3
return [2, -3, 4], since all the values happen only once, 
return all of them in any order.
Examples 2
Input:

  5
 /  \
2   -5
return [2], since 2 happens twice, however -5 only occur once.
Note: You may assume the sum of values in any subtree is 
in the range of 32-bit signed integer.
*/

//solution
typedef pair<int, int> mypair;

class Solution {
	unordered_map<int, int> map;
public:
	static bool mysort(const mypair& p1, const mypair& p2) {
		if (p1.second > p2.second)
			return true;
		return false;
	}
	int sumtree(TreeNode* root) {
		if (root == nullptr)
			return 0;
		int lsum = sumtree(root->left);
		int rsum = sumtree(root->right);
		int csum = lsum + rsum + root->val;
		map[csum]++;
		return csum;
	}

	vector<int> findFrequentTreeSum(TreeNode* root) {
		sumtree(root);
		vector<mypair> vec;
		copy(map.begin(), map.end(), back_inserter(vec));
		sort(vec.begin(), vec.end(), mysort);

		vector<int> result;
		int pfreq = 0;
		for (auto it = vec.begin(); it != vec.end(); ++it) {
			mypair& p = *it;
			if (p.second < pfreq)
				break;
			result.push_back(p.first);
			pfreq = p.second;
		}

		return result;
	}
};
