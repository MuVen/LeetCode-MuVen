/*
On a 2-dimensional grid, there are 4 types of squares:

1 represents the starting square.  There is exactly one starting square.
2 represents the ending square.  There is exactly one ending square.
0 represents empty squares we can walk over.
-1 represents obstacles that we cannot walk over.
Return the number of 4-directional walks from the starting square to the ending 
square, that walk over every non-obstacle square exactly once.

 

Example 1:

Input: [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
Output: 2
Explanation: We have the following two paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
Example 2:

Input: [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
Output: 4
Explanation: We have the following four paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
Example 3:

Input: [[0,1],[2,0]]
Output: 0
Explanation: 
There is no path that walks over every empty square exactly once.
Note that the starting and ending square can be anywhere in the grid.
 */
 
 //solution
 int xM[4] = {-1,0,1,0};
int yM[4] = {0,1,0,-1};

class Solution {
    vector<vector<int>> mgrid;
    int row, col;
    int count;
    int tsteps;
public:
    bool isValid(int x, int y){
        if(x >= 0 && x <= row-1 && y >= 0 && y <= col-1 && mgrid[x][y] != -1)
            return true;
        return false;
    }
    
    void process(int x, int y, int step){
        if(!isValid(x,y))
            return;
        
        if(mgrid[x][y] == 2){
            if(step+1 == tsteps)
                count++;
            return;
        }
        
       
        mgrid[x][y] = -1;
        for(int i = 0; i < 4; i++){
            int nx = x + xM[i];
            int ny = y + yM[i];
            process(nx, ny, step+1);
        }
        mgrid[x][y] = 0;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        mgrid = move(grid);
        count = 0;
        int x, y;
        tsteps = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(mgrid[i][j] == 1){
                    x = i;
                    y = j;
                }
                if(mgrid[i][j] != -1)
                    tsteps++;
            }
        }
        process(x, y, 0);
        return count;
    }
};