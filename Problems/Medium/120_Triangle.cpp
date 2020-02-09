/*
Given a triangle, find the minimum path sum from top to bottom. 
Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:

Bonus point if you are able to do this using only O(n) extra space, 
where n is the total number of rows in the triangle.
*/

//solution
class Solution {
    vector<vector<int>> ntriangle;
    vector<vector<int>> cache;
    int nrow, ncol;
    int ans = INT_MAX;
public:
    int mpaths(int row, int col){
        if(row >= nrow)
            return 0;
        
        if(cache[row][col] != -1)
            return cache[row][col];

        return cache[row][col] = ntriangle[row][col] + 
                                 min(mpaths(row+1, col), mpaths(row+1, col+1));
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        ntriangle = move(triangle);
        nrow = ntriangle.size();
        ncol = ntriangle[nrow-1].size();
        cache.resize(nrow, vector<int>(ncol, -1));
        return mpaths(0,0);
    }
};