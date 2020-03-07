/*
Given an integer array nums, find the contiguous subarray 
(containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another 
solution using the divide and conquer approach, which is more subtle.
*/

//solution
#define MAX(a,b) ((a)>(b)?(a):(b))

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        int curr_max = nums[0], max_so_far = nums[0];
        for(int i = 1; i < size; i++){
            curr_max = MAX(nums[i], curr_max+nums[i])            ;
            max_so_far = MAX(curr_max, max_so_far);
        }
        return max_so_far;
    }
};