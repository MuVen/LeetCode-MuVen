/*
Given an array of non-negative integers, you are initially positioned at the 
first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

Example 1:

Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum
             jump length is 0, which makes it impossible to reach the last index.
*/

//solution
class Solution {
    vector<int> mnums;
    vector<int> cache;
public:
    bool canJumpUtil(int index){
        if(index >= mnums.size())
            return false;
        
        if(index == mnums.size()-1)
            return true;
        
        if(cache[index] != -1)
            return cache[index] == 0 ? false : true;
        
        int val = mnums[index];
        for(int i = 1; i <= val; i++){
            if(canJumpUtil(index + i)){
                return true;
            }
        }
        
        cache[index] = 0;
        return false;
    }
    
    bool canJump(vector<int>& nums) {
        cache.resize(nums.size(), -1);
        mnums = move(nums);
        return canJumpUtil(0);
    }
};