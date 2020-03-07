/*
Given an array nums, write a function to move all 0's to the end of it 
while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/

//solution
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size() == 0)
            return;
        
        int i = 0;
        for(int n = 0; n < nums.size(); n++){
            if(nums[n] != 0){
                swap(nums[n], nums[i++]);
            }
        }
    }
};