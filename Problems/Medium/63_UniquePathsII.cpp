/*
A robot is located at the top-left corner of a m x n grid 
(marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. 
The robot is trying to reach the bottom-right corner of the grid 
(marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. 
How many unique paths would there be?



An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Note: m and n will be at most 100.

Example 1:

Input:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
*/

//solution
class Solution {
    vector<vector<int>> mgrid;
    vector<vector<int>> cache;
    int row, col;
public:
    inline bool isValid(int x, int y){
        if(x >= 0 && x < row && y >= 0 && y < col && mgrid[x][y] == 0)
            return true;
        return false;
    }
    
    int process(int x, int y){
        if(!isValid(x,y))
            return 0;
        
        if(cache[x][y] != -1)
            return cache[x][y];
        
        //cout<<x<<" "<<y<<endl;
        int temp = mgrid[x][y];
        mgrid[x][y] = 9;
        
        if(x == row - 1 && y == col - 1){
            mgrid[x][y] = temp;
            return 1;
        }
        
        int count = process(x+1, y) + process(x, y+1);
        mgrid[x][y] = temp;
        return cache[x][y] = count;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        mgrid = move(obstacleGrid);
        row = mgrid.size();
        col = mgrid[0].size();
        cache.resize(row,vector<int>(col,-1));
        return process(0,0);
    }
};