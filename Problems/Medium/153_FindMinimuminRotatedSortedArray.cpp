/*
Suppose an array sorted in ascending order is rotated at some pivot unknown 
to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

You may assume no duplicate exists in the array.

Example 1:

Input: [3,4,5,1,2] 
Output: 1
Example 2:

Input: [4,5,6,7,0,1,2]
Output: 0
*/

//solution
class Solution {
    vector<int> mnums;
public:
    
    int findPivot(){
        int low = 0, high = mnums.size()-1;
        while(low <= high){
            int mid = (low+high)/2;
            if(mid < mnums.size() - 1 && mnums[mid] > mnums[mid+1])
                return mid;
            
            if(mnums[0] <= mnums[mid]){
                //first half is sorted;
                low = mid + 1;
            }else{
                //second half is sorted;
                high = mid - 1;
            }
        }

        return -1;
    }
    
    int findMin(vector<int>& nums) {
        mnums = move(nums);
        int index = findPivot();
        if(index == -1)
           return mnums[0];
        return mnums[index+1];
    }
};