/*
Given a non-empty array of integers, return the third maximum number 
in this array. If it does not exist, return the maximum number. 
The time complexity must be in O(n).

Example 1:
Input: [3, 2, 1]

Output: 1

Explanation: The third maximum is 1.
Example 2:
Input: [1, 2]

Output: 2

Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
Example 3:
Input: [2, 2, 3, 1]

Output: 1

Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.
*/

//solution
#define MAX(a,b) ((a)>(b)?(a):(b))

class Solution {
public:
	int thirdMax(vector<int>& nums) {
		long long int fmax = LLONG_MIN, smax = LLONG_MIN, tmax = LLONG_MIN;
		for (int i = 0; i < nums.size(); i++){
			if (nums[i] == fmax || nums[i] == smax || nums[i] == tmax)
				continue;

			if (nums[i] > fmax){
				tmax = smax;
				smax = fmax;
				fmax = nums[i];
			}
			else if (nums[i] > smax){
				tmax = smax;
				smax = nums[i];
			}
			else if (nums[i] > tmax){
				tmax = nums[i];
			}
		}

		if (tmax != LLONG_MIN)
			return tmax;
		
		return MAX(fmax,smax);
	}
};