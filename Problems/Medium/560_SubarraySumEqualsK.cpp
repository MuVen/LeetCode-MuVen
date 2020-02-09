/*
Given an array of integers and an integer k, you need to find the total 
number of continuous subarrays whose sum equals to k.

Example 1:
Input:nums = [1,1,1], k = 2
Output: 2
Note:
The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].
*/

//solution
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0, sum = 0;
        unordered_map<int,int> map;
        map[0] = 1;
        
        
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(map.find(sum-k) != map.end()){
                count += map[sum-k];
            }
            map[sum]++;
        }
        return count;
    }
};