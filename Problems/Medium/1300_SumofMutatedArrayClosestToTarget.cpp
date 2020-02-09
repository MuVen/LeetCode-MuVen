/*
Given an integer array arr and a target value target, return the integer value 
such that when we change all the integers larger than value in the given array 
to be equal to value, the sum of the array gets as close as possible 
(in absolute difference) to target.

In case of a tie, return the minimum such integer.

Notice that the answer is not neccesarilly a number from arr.

Example 1:
Input: arr = [4,9,3], target = 10
Output: 3
Explanation: When using 3 arr converts to [3, 3, 3] which sums 9 
and that's the optimal answer.

Example 2:
Input: arr = [2,3,5], target = 10
Output: 5
Example 3:

Input: arr = [60864,25176,27249,21296,20204], target = 56803
Output: 11361
 
*/

//solution
class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int sum = 0, mv = INT_MIN;
        for(auto i : arr){
            sum += i;
            mv = max(mv, i);
        }
        
        if(sum == target) return mv;
        int low = 1, high = mv;
        while(low < high){
            int mid = (low + high) / 2;
            sum = 0;
            for(auto i : arr) sum += i > mid ? mid : i;
            if(sum >= target) high = mid;
            else low = mid+1;
        }
        
        
        int s1 = 0, s2 = 0;
        for(auto i : arr){
            s1 += i > low ? low : i;
            s2 += i > low-1 ? low-1:i;
        }
        
        return abs(s2-target) <= abs(s1-target) ? low-1 : low;
    }
};