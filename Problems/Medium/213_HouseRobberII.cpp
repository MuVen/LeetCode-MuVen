/*
You are a professional robber planning to rob houses along a street.
Each house has a certain amount of money stashed. All houses at this place are 
arranged in a circle. That means the first house is the neighbor of the last one. 
Meanwhile, adjacent houses have security system connected and it will automatically
contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house,
determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
             because they are adjacent houses.
Example 2:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
*/

//solution
class Solution {
	vector<int> mnums;
	vector<bool> mvisited;
	vector<vector<int>> cache;
	int msize;
public:
	int robHome(int index){
		if (index >= msize)
			return 0;

		if (cache[index][mvisited[0]] != -1)
			return cache[index][mvisited[0]];

        //cache is 2d cache;
        //its based on first node visited or not visited for a given index.

		int v1 = 0, v2 = 0;
		mvisited[index] = true;
		if (index == msize - 1 && mvisited[0] == true){
			v1 = 0;
		}
		else{
			v1 = mnums[index] + robHome(index + 2);
		}
		mvisited[index] = false;

		v2 = robHome(index + 1);
		return cache[index][mvisited[0]] = max(v1, v2);
	}

	int rob(vector<int> nums) {
		mnums = move(nums);
		msize = mnums.size();
        if (msize == 1)
			return mnums[0];
		mvisited.resize(msize, false);
		cache.resize(msize, vector<int>(2, -1));
		return robHome(0);
	}
};