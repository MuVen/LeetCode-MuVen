/*
Given an array of integers A sorted in non-decreasing order, 
return an array of the squares of each number, also in sorted non-decreasing order.

 

Example 1:

Input: [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Example 2:

Input: [-7,-3,2,3,11]
Output: [4,9,9,49,121]
 

Note:

1 <= A.length <= 10000
-10000 <= A[i] <= 10000
A is sorted in non-decreasing order.
*/

//solution
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int i = 0;
        for(i = 0; i < A.size(); i++){
            if(A[i] > 0)
                break;
        }
        
        int j = i;
        i = i-1;

        vector<int> ans;
        while(i >= 0 && j < A.size()){
            if(A[i]*A[i] < A[j]*A[j]){
                ans.push_back(A[i]*A[i]);
                i--;
            }else{
                ans.push_back(A[j]*A[j]);
                j++;
            }     
        }
        
        while(i >= 0){
            ans.push_back(A[i]*A[i]);
            i--;
        }
        
        while(j < A.size()){
            ans.push_back(A[j]*A[j]);
            j++;
        }
        
        return ans;
    }
};