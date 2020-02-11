/*
540. Single Element in a Sorted Array

You are given a sorted array consisting of only integers where every element appears
exactly twice, except for one element which appears exactly once. Find this single 
element that appears only once.


Example 1:

Input: [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: [3,3,7,7,10,11,11]
Output: 10
 

Note: Your solution should run in O(log n) time and O(1) space.
*/
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start = 0, end = nums.size()-1;
        while(start < end){
            int mid = (start+end)/2; 
            //check only odd indexes; odd index == even index;
            mid = mid % 2 == 0 ? mid + 1 : mid;
            //if odd index == even index, then culprit is on the right side. 1 1 2 2 3 4 4
            if(nums[mid] == nums[mid-1]) start = mid + 1;
            //else the culprit is on the left side 1 1 2 3 3 4 4
            else end = mid - 1;
        }
        return nums[start];
    }
};