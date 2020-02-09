/*
Given an array of integers nums sorted in ascending order,
 find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

*/
//solution
class Solution {
    vector<int> num;
public:
    
    int findLowerBound(int start, int end, int target){
        while(start <= end){
            int mid = (end-start)/2 + start;
            if(mid == 0 && num[mid] == target)
                return 0;
            if(num[mid] == target && num[mid-1] != target)
                return mid;
            if(target > num[mid]){
                start = mid + 1;
            }else if(target < num[mid] || target == num[mid]){
                end = mid - 1;
            }
        }
        return -1;
    }

    int findUpperBound(int start, int end, int target){
        while(start <= end){
            int mid = (end-start)/2 + start;
            if(mid == num.size()-1 && num[mid] == target)
                return mid;
            if(num[mid] == target && num[mid+1] != target)
                return mid;
            if(target > num[mid] || target == num[mid])
                start = mid + 1;
            else if(target < num[mid])
                end = mid - 1;
        }            
        return -1;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        num = move(nums);
        int lb = findLowerBound(0, num.size()-1, target);
        if(lb == -1)
            return vector<int>{-1,-1};
    
        vector<int> res;
        res.resize(2,0);
        res[0] = lb;
        int ub = findUpperBound(0, num.size()-1, target);
        res[1] = ub;
        return res;
    }
};