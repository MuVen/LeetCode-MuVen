/*
Given an integer array nums, find the sum of the elements between 
indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.
*/

//solution
class NumArray {
    vector<int> mnums;
public:
    NumArray(vector<int>& nums) {
        mnums = move(nums);
        for(int i = 1; i < mnums.size(); i++){
            mnums[i] = mnums[i]+mnums[i-1];
        }
    }
    
    int sumRange(int i, int j) {
        if(i == 0)
            return mnums[j];
        return mnums[j] - mnums[i-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */