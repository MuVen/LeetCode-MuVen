/*
Given an array nums of n integers, are there elements a, b, c in nums such 
that a + b + c = 0? Find all unique triplets in the array which gives the
 sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

//solution
class Solution {
	vector<vector<int>> res;
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		if(nums.size() < 3)
			return res;
		/*
			-4 -1 -1 0 1 2
			-2 0 0 2 2
			
			have to find unique triplets.
			if nums[i] == x then the next value of i should such that nums[i] != x;
			once you find the triplet nums[i] + nums[j] + nums[k] == 0;
			then also move j & k to next value which is not equal to current nums[j] and nums[k].
		*/
        sort(nums.begin(), nums.end());
		int i, j, k, sum;
		for(i = 0; i < nums.size() - 2; i++){
            if(i > 0 && nums[i] == nums[i-1])
                continue;
			j = i + 1, k = nums.size() -1;
			while(j < k){
				sum = nums[i]+nums[j]+nums[k];
				if( sum == 0){
					res.push_back({nums[i], nums[j], nums[k]});
					while(j < k && nums[j] == nums[j+1]) j++;
					while(j < k && nums[k] == nums[k-1]) k--;
					j++;
					k--;
				}else if(sum > 0){
					k--;
				}else if(sum < 0){
					j++;
				}
			}
		}
		return res;
    }
};