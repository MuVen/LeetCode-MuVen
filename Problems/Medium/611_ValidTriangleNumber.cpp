/*
Given an array consists of non-negative integers, your task is to count the 
number of triplets chosen from the array that can make triangles if we take them
 as side lengths of a triangle.
 
Example 1:
Input: [2,2,3,4]
Output: 3
Explanation:
Valid combinations are: 
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3
Note:
The length of the given array won't exceed 1000.
The integers in the given array are in the range of [0, 1000].

*/

//solution
class Solution {
    int count = 0;
public:    
    int triangleNumber(vector<int>& mnums) {
        if(mnums.size() < 3)return 0;
        sort(mnums.begin(), mnums.end());
        int i, j, k;
        k = mnums.size()-1;
        while(k >= 2){
            i = 0, j = k-1;
            while(i < j){
                if(mnums[i]+mnums[j] > mnums[k]){
                    count += j-i;
                    j--;
                }else{
                    i++;
                }
            }
            k--;
        }
        return count;
    }
};