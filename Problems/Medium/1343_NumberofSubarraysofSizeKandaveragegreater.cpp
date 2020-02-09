/*
Given an array of integers arr and two integers k and threshold.

Return the number of sub-arrays of size k and average greater than or equal to threshold.

 

Example 1:
Input: arr = [2,2,2,2,5,5,5,8], k = 3, threshold = 4
Output: 3
Explanation: Sub-arrays [2,5,5],[5,5,5] and [5,5,8] have averages 4, 5 and 6 
respectively.All other sub-arrays of size 3 have averages less than 4 (the threshold).

Example 2:
Input: arr = [1,1,1,1,1], k = 1, threshold = 0
Output: 5

Example 3:
Input: arr = [11,13,17,23,29,31,7,5,2,3], k = 3, threshold = 5
Output: 6
Explanation: The first 6 sub-arrays of size 3 have averages greater than 5. 
Note that averages are not integers.

Example 4:
Input: arr = [7,7,7,7,7,7,7], k = 7, threshold = 7
Output: 1

Example 5:
Input: arr = [4,4,4,4], k = 4, threshold = 1
Output: 1
 

Constraints:

1 <= arr.length <= 10^5
1 <= arr[i] <= 10^4
1 <= k <= arr.length
0 <= threshold <= 10^4
*/

//solution
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        vector<int> sums;
        int sum = 0;
        for(auto a : arr){
            sum += a;
            sums.push_back(sum);
        }
        
        int count = 0, s = 0;
        for(int e = k-1; e < arr.size(); e++){
            s = e - k + 1;
            int sasum = 0;
            
            if(s > 0)
                sasum = sums[e] - sums[s-1];
            else
                sasum = sums[e];
            
            if((float)sasum / k >= threshold)
                count++;
        }
        
        return count;
    }
};