/*
Given an array nums of n integers and an integer target, 
find three integers in nums such that the sum is closest to target.
Return the sum of the three integers. You may assume that each input would have
exactly one solution.

Example:

Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

//solution
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = INT_MAX, closeSum = 0;
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int i,j,k,sum;
        for(i = 0; i < size-2; i++){
            j = i + 1, k = size-1;
            while(j < k){
                sum = nums[i]+nums[j]+nums[k];
                if(sum == target){
                     return target;
                }else if(sum > target){
                    k--;
                }else{
                    j++;
                }
                int adiff = abs(target-sum);
                if(adiff < ans){
                    ans = adiff;
                    closeSum = sum;
                }
            }
        }
        
        return closeSum;    
    }
};