/*
Given an integer array nums, find the contiguous subarray within an array 
(containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*/

//solution
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int front = 1;
        int back = 1;
        int size = nums.size();
        int ans = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            front *= nums[i];
            back *= nums[size - i - 1];
            ans = max(ans, max(front, back));
            front = front == 0 ? 1 : front;
            back = back == 0 ? 1 : back;
        }
        return ans;
    }
};