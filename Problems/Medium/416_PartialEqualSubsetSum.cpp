/*
Given a non-empty array containing only positive integers, find if the array
 can be partitioned into two subsets such that the sum of elements in both 
 subsets is equal.

Note:

Each of the array element will not exceed 100.
The array size will not exceed 200.
 

Example 1:

Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].
 

Example 2:

Input: [1, 2, 3, 5]

Output: false

Explanation: The array cannot be partitioned into equal sum subsets.
 
*/

//solution
class Solution {
    vector<int> mnums;
    vector<vector<int>> cache;
public:
    bool canPartitionUtil(int index, int target){
        if(target < 0 || index < 0)
            return false;
        
        if(target == 0)
            return true;
        
        if(cache[index][target] != -1)
            return cache[index][target];
        
        return cache[index][target] = 
               canPartitionUtil(index-1, target - mnums[index]) ||
               canPartitionUtil(index-1, target);
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto i : nums)
            sum += i;
        if (sum % 2 != 0)
            return false;
        cache.resize(nums.size()+1, vector<int>((sum/2)+5, -1));
        mnums = move(nums);
        return canPartitionUtil(mnums.size()-1, sum/2);
    }
};