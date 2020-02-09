/*
Given a m x n grid filled with non-negative numbers, find a path from 
top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/

//solution
class Solution {
    vector<vector<int>> mgrid;
    vector<vector<int>> cache;
    int row, col;
public:
    bool isValid(int x, int y){
        if(x < 0 || x >= row || y < 0 || y >= col)
            return false;
        return true;
    }
    
    int minPathSumUtil(int x, int y){
        if(!isValid(x,y))
            return INT_MAX;
        
        if(x == row-1 && y == col-1)
            return mgrid[x][y];
        
        if(cache[x][y] != -1)
            return cache[x][y];
        
        int v1 = minPathSumUtil(x, y + 1);
        int v2 = minPathSumUtil(x+1, y);
        return cache[x][y] = min(v1,v2) + mgrid[x][y];
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        mgrid = move(grid);
        row = mgrid.size();
        col = mgrid[0].size();
        if(row == 0 || col == 0)
            return 0;
        cache.resize(row, vector<int>(col, -1));
        return minPathSumUtil(0,0);
    }
};