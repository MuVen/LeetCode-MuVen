/*
Given an array, rotate the array to the right by k steps, where k is non-negative.

Example 1:

Input: [1,2,3,4,5,6,7] and k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: [-1,-100,3,99] and k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
Note:

Try to come up as many solutions as you can, there are
 at least 3 different ways to solve this problem.
Could you do it in-place with O(1) extra space?
*/

//solution
class Solution {
public:
	int gcd(int a, int b){
		if (a == 0)
			return b;

		return gcd(b%a, a);
	}

	void rotate(vector<int>& nums, int k) {
		if (nums.size() == 0 || k == 0)
			return;

		int size = nums.size();

		if (size == 1)
			return;

		int count = gcd(k, size);
		int j, temp, ti;
		for (int i = 0, ti = size - 1; i < count; i++, ti--){
			j = ti;
			temp = nums[j];
			while (1){
				int val = (j - k);
				while (val < 0)
					val = size + val;
				if (val == ti)
					break;
				nums[j] = nums[val];
				j = val;
			}
			nums[j] = temp;
		}
	}
};