/*
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), 
some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? 
You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]
*/

//solution
#define ABS(x) ((x)<(0)?(-x):(x))

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        if(nums.size() == 0)
            return vector<int>{};
 
        for(int i = 0; i < nums.size(); i++){
            int index = ABS(nums[i])-1;
            nums[index] = nums[index] > 0 ? nums[index]*-1 : nums[index];
        }
        
        vector<int> res;
        for(int i =0; i < nums.size();i++){
            if(nums[i]>0)
                res.push_back(i+1);
        }
        
        return move(res);
    }
};