/*
Given a m * n grid, where each cell is either 0 (empty) or 1 (obstacle). 
In one step, you can move up, down, left or right from and to an empty cell.

Return the minimum number of steps to walk from the upper left corner (0, 0)
 to the lower right corner (m-1, n-1) given that you can eliminate at most 
k obstacles. If it is not possible to find such walk return -1.

 

Example 1:

Input: 
grid = 
[[0,0,0],
 [1,1,0],
 [0,0,0],
 [0,1,1],
 [0,0,0]], 
k = 1
Output: 6
Explanation: 
The shortest path without eliminating any obstacle is 10. 
The shortest path with one obstacle elimination at position (3,2) is 6.
Such path is (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2) -> (3,2) -> (4,2).
 

Example 2:

Input: 
grid = 
[[0,1,1],
 [1,1,1],
 [1,0,0]], 
k = 1
Output: -1
Explanation: 
We need to eliminate at least two obstacles to find such a walk.
 

Constraints:

grid.length == m
grid[0].length == n
1 <= m, n <= 40
1 <= k <= m*n
grid[i][j] == 0 or 1
grid[0][0] == grid[m-1][n-1] == 0
*/

//solution
#define CA 41
int xM[] = {-1,0,1,0};
int yM[] = {0,1,0,-1};
//Mistake, defined wrong directions;

int cache[CA][CA][CA*CA];

class Solution {
    int row, col;
    vector<vector<int>> mgrid;
    int K;
    int ans = INT_MAX;
public:
    
    inline bool isValid(int x, int y){
        if(x < 0 || x >= row || y < 0 || y >= col || mgrid[x][y] == 9)
            return false;
        return true;
    }
    
    //3 parameters are varying, x, y, and remove obstacles.
    //define a cached and save x, y, RO in the cache
    int process(int x, int y, int dist, int RO){
        if(!isValid(x,y))
            return INT_MAX;
        
        if(RO < 0 || dist > ans)
            return INT_MAX;
        
        if(x == row-1 && y == col-1 && RO >= 0){
            ans = min(ans, dist);
            return cache[x][y][RO] = ans;
        }
        
        if(cache[x][y][RO] != -1)
            return cache[x][y][RO];
        
        int temp = mgrid[x][y];
        mgrid[x][y] = 9;
        
        for(int i = 0; i < 4; i++){
            int nx = x + xM[i];
            int ny = y + yM[i];
            ans = min(process(nx, ny, dist+1, temp == 1 ? RO - 1 : RO), ans);
        }
        
        mgrid[x][y] = temp;
        return cache[x][y][RO] = ans;
    }
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        mgrid = move(grid);
        row = mgrid.size();
        col = mgrid[0].size();
        K = k;
        if(row == 0)
            return 0;
        for(int i = 0; i < CA; i++)
            for(int j = 0; j < CA; j++)
                for(int k = 0; k < CA*CA; k++)
                    cache[i][j][k] = -1;
        return process(0,0,0,k) == INT_MAX ? -1 : ans;
    }
};