/*
Given an integer array sorted in non-decreasing order, there is exactly 
one integer in the array that occurs more than 25% of the time.

Return that integer.

 

Example 1:

Input: arr = [1,2,2,6,6,6,6,7,10]
Output: 6
 

Constraints:

1 <= arr.length <= 10^4
0 <= arr[i] <= 10^5
*/

//solution
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        if(arr.size() == 0)
            return 0;
        
        if(arr.size() == 1)
            return arr[0];
        
        int num = arr[0];
        int count = 1;
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] == num)
                count++;
            else{
                count = 1;
                num = arr[i];
            }
            if(count > arr.size()/4)
                return num;
        }
        
        return -1;
    }
};