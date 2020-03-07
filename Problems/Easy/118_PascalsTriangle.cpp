/*

Given a non-negative integer numRows, generate the first numRows of
 Pascal's triangle.


In Pascal's triangle, each number is the sum of the two numbers directly
 above it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

//solution
class Solution {
    vector<vector<int>> res;
public:
    vector<int> generateUtil(int row){
        if(row == 1){
            res.push_back(vector<int>{1});
            return vector<int>{1};
        }
        
        vector<int> ret = generateUtil(row-1);
        vector<int> curr(row, 1);
        for(int i = 1; i < row - 1; i++)
            curr[i] = ret[i-1] + ret[i];
        
        res.push_back(curr);
        return curr;
    }
    
    vector<vector<int>> generate(int numRows) {
        if(numRows == 0)
            return res;

        generateUtil(numRows);
        return res;
    }
};class Solution {
    vector<vector<int>> res;
public:
    vector<int> generateUtil(int row){
        if(row == 1){
            res.push_back(vector<int>{1});
            return vector<int>{1};
        }
        
        vector<int> ret = generateUtil(row-1);
        vector<int> curr(row, 1);
        for(int i = 1; i < row - 1; i++)
            curr[i] = ret[i-1] + ret[i];
        
        res.push_back(curr);
        return curr;
    }
    
    vector<vector<int>> generate(int numRows) {
        if(numRows == 0)
            return res;

        generateUtil(numRows);
        return res;
    }
};