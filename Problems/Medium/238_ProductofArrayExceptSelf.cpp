/*
Given an array nums of n integers where n > 1,  return an array output such that
 output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not 
count as extra space for the purpose of space complexity analysis.)

*/
//solution
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int size = nums.size();
        
        vector<int> a;
        a.resize(size, 0);
        
        int prod = 1;
        for(int i = 0; i < size; i++){
            a[i] = prod;
            prod *= nums[i];
        }
        
        prod = 1;
        for(int i = size-1; i >= 0; i--){
            a[i] *= prod;
            prod *= nums[i];
        }
        
        return move(a);
    }
};