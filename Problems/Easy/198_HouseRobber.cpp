/*
You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed, the only constraint 
stopping you from robbing each of them is that adjacent houses have 
security system connected and it will automatically contact the police if
 two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of 
each house, determine the maximum amount of money you can rob tonight without 
alerting the police.

Example 1:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9)
 and rob house 5 (money = 1).
             Total amount you can rob = 2 + 9 + 1 = 12.
*/

//solution
class Solution {
    vector<int> mnums;
    vector<int> cache;
    int size;
public:
    int robutil(int index){
        if(index >= size)
            return 0;
        
        if(cache[index] != -1)
            return cache[index];
        //rob the current home and move to index + 2;
        int v1 = mnums[index] + robutil(index+2);
        //ignore robbing the current home and move to index + 1;
        int v2 = robutil(index+1);
        //we return max value robbing the current home or ignoring the current home;
        return cache[index] = max(v1,v2);
    }
    
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        
        mnums = move(nums);
        size = mnums.size();
        cache.resize(size,-1);
        return robutil(0);
    }
};