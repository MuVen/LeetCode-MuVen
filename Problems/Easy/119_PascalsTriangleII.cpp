/*
Given a non-negative index k where k ≤ 33, return the kth index row of 
the Pascal's triangle.

Note that the row index starts from 0.


In Pascal's triangle, each number is the sum of the two numbers directly
 above it.

Example:

Input: 3
Output: [1,3,3,1]
Follow up:

Could you optimize your algorithm to use only O(k) extra space?
*/

//solution
class Solution {

public:

    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0) return vector<int>{1};
        
        vector<int> res = getRow(rowIndex-1);
        vector<int> nres;
        nres.resize(res.size()+1);
        nres[0] = 1;
        nres[res.size()]=1;
        for(int i = 1; i < rowIndex; i++){
            nres[i] = res[i-1]+res[i];
        }
        return nres;
    }
};