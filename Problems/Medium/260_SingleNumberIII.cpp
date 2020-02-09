/*
Given an array of numbers nums, in which exactly two elements appear only once 
and all the other elements appear exactly twice. Find the two elements that 
appear only once.

Example:

Input:  [1,2,1,3,2,5]
Output: [3,5]
Note:

The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. 
Could you implement it using only constant space complexity?
*/
//solutionclass Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if(nums.size() == 0)
            return vector<int>{};
        
        int val = 0;
        for(int i = 0; i < nums.size(); i++){
            val ^= nums[i];
        }
        
        int sone = (val & ~(val-1));
        int fnum = 0, snum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]&sone)
                fnum ^= nums[i];
            else
                snum ^= nums[i];
        }
        
        vector<int> res;
        res.push_back(fnum);
        res.push_back(snum);
        return move(res);
    }
};