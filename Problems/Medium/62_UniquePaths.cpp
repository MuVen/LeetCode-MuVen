/*
A robot is located at the top-left corner of a m x n grid 
(marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. 
The robot is trying to reach the bottom-right corner of the grid 
(marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 7 x 3 grid. How many possible unique paths are there?

Note: m and n will be at most 100.

Example 1:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right
Example 2:

Input: m = 7, n = 3
Output: 28
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
    
    int uniquePaths(int m, int n) {
        mgrid.resize(m, vector<int>(n,0));
        cache.resize(m, vector<int>(n,-1));
        row = m, col = n;
        return process(0,0);
    }
};