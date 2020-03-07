/*
Given an array arr, replace every element in that array with the 
greatest element among the elements to its right, 
and replace the last element with -1.

After doing so, return the array.

 

Example 1:

Input: arr = [17,18,5,4,6,1]
Output: [18,6,6,6,1,-1]
 

Constraints:

1 <= arr.length <= 10^4
1 <= arr[i] <= 10^5
*/

//solution
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        if(arr.size() == 0)
            return vector<int>{};
        vector<int> res;
        res.resize(arr.size(),0);
        
        res[arr.size()-1] = -1;
        int maxv = arr[arr.size()-1];
        for(int i = arr.size()-2; i >= 0; i--){
            res[i] = maxv;
            maxv = max(maxv, arr[i]);
        }
        
        return res;
    }
};