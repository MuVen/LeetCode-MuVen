/*
Given an unsorted integer array, find the smallest missing positive integer.

Example 1:

Input: [1,2,0]
Output: 3
Example 2:

Input: [3,4,-1,1]
Output: 2
Example 3:

Input: [7,8,9,11,12]
Output: 1
Note:

Your algorithm should run in O(n) time and uses constant extra space.
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0, n = nums.size();
        //max answer will be size of array n, n+1;
        //reset all negative values and values above n to INT_MAX;
        for(; i < n; i++)
            if(nums[i] <= 0 || nums[i] > n)
                nums[i] = INT_MAX;

        //as answer can n+1 add one INT_MAX at the end;
        nums.push_back(INT_MAX);
        for(i = 0; i < n; i++){
            //if abs values of nums[i] == INT_MAX; ignore that index;
            if(abs(nums[i]) == INT_MAX) 
                continue;

            //else make the value in that index negative;
            if(nums[abs(nums[i])] > 0)
                nums[abs(nums[i])] *= -1;
        }
        
        //now traverse from 1 to <= n, if value in any index > 0;
        //return that index as answer; else last index+1 will be the answer;
        for(i = 1; i <= n; i++){
            if(nums[i] > 0)
                break;
        }
        
        return i;
    }
};