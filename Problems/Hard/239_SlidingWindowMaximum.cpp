/*
Given an array nums, there is a sliding window of size k which is moving from
 the very left of the array to the very right. 
You can only see the k numbers in the window. 
Each time the sliding window moves right by one position.
Return the max sliding window.

Example:

Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
Output: [3,3,5,5,6,7] 
Explanation: 

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Note:
You may assume k is always valid, 1 ≤ k ≤ input array's size for non-empty array.

Follow up:
Could you solve it in linear time?
*/

//solution
class Solution {
	deque<int> deq;
	vector<int> result;
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		for (int i = 0; i < nums.size(); i++){
			if (!deq.empty() && deq.front() == i - k)
				deq.pop_front();

			while (!deq.empty() && nums[i] > nums[deq.back()])
				deq.pop_back();
			
			deq.push_back(i);
			if (i >= k - 1)
				result.push_back(nums[deq.front()]);

		}
		return move(result);
	}
};