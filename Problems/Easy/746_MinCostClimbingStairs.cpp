/*
On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).

Once you pay the cost, you can either climb one or two steps. 
You need to find minimum cost to reach the top of the floor, and 
you can either start from the step with index 0, or the step with index 1.

Example 1:
Input: cost = [10, 15, 20]
Output: 15
Explanation: Cheapest is start on cost[1], pay that cost and go to the top.
Example 2:
Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
Output: 6
Explanation: Cheapest is start on cost[0], and only step on 1s, skipping cost[3].
Note:
cost will have a length in the range [2, 1000].
Every cost[i] will be an integer in the range [0, 999].
*/

//solution
#define MIN(a,b) ((a)>(b)?(b):(a))

class Solution {
	vector<int> vc;
	vector<int> cache;
public:
	int getmin(int top){
		if (top < 0)
			return 0;
		if (top == 0)
			return vc[0];
		if (cache[top] != -1)
			return cache[top];
		int val = top == vc.size() ? 0 : vc[top];
		int m1 = val + getmin(top - 1);
		int m2 = val + getmin(top - 2);
		return cache[top] = MIN(m1, m2);
	}

	int minCostClimbingStairs(vector<int>& cost) {
		vc = move(cost);
		cache.resize(vc.size()+1, -1);
		return getmin(vc.size());
	}
};