/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to 
you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index,
 otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

*/
//solution
class Solution {
    vector<int> mnums;
    int mtarget;
public:
    int findPivot(int low, int high){
        if(low > high)
            return -1;

        int mid = (low + high) / 2;
        if(mid <  high && mnums[mid] > mnums[mid+1])
            return mid;
        if(mid > low && mnums[mid] < mnums[mid-1])
            return mid-1;
        
        if(mnums[low] <= mnums[mid])
            return findPivot(mid+1, high);
        return findPivot(low, mid-1);
    }
    
    int binarySearch(int low, int high){
        if(low > high)
            return -1;
        int mid = (low+high)/2;
        if(mnums[mid] == mtarget)
            return mid;
        
        if(mtarget > mnums[mid])
            return binarySearch(mid+1, high);
        
        return binarySearch(low, mid-1);
    }
    
    int search(vector<int>& nums, int target) {
        mnums = move(nums);
        mtarget = target;
        int index = findPivot(0, mnums.size()-1);
        if(index == -1)
            return binarySearch(0, mnums.size()-1);
        if(target >= mnums[0] && target <= mnums[index])
            return binarySearch(0, index);
        
        return binarySearch(index+1, mnums.size()-1);
    }
};