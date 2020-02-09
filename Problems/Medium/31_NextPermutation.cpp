/*
Implement next permutation, which rearranges numbers into the lexicographically 
next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible
 order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding
 outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

*/

//solution
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()<=1) return;
        int n= nums.size(), pos, i;
        //find pivot element from last; find element i > i - 1;
        //i-1 is pivot element; if i - 1 is 0 then reverse entire vector;
        //from from size-1 to i-1 find element which is greater than i-1 element
        //swap [i-1] and greater element from [i, size]
        //reverse [i, size] array;
        //https://leetcode.com/problems/next-permutation/discuss/13994/Readable-code-without-confusing-ij-and-with-explanation
        for(i=n-1; i>=1; i--){
            if(nums[i-1]<nums[i])
               break;
        }
        if(i==0) return reverse(nums.begin(), nums.end());
        pos=i-1;
        
        for(i=n-1; i>pos && i>=0; i--){
            if(nums[i]>nums[pos]){
                swap(nums[i], nums[pos]);
                break;
            }
        }
        reverse(nums.begin() + pos+1, nums.end());
    }
};