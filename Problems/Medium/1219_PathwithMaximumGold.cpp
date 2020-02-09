/*
In a gold mine grid of size m * n, each cell in this mine has an integer 
representing the amount of gold in that cell, 0 if it is empty.

Return the maximum amount of gold you can collect under the conditions:

Every time you are located in a cell you will collect all the gold in that cell.
From your position you can walk one step to the left, right, up or down.
You can't visit the same cell more than once.
Never visit a cell with 0 gold.
You can start and stop collecting gold from any position in the grid that has some gold.
 

Example 1:
Input: grid = [[0,6,0],[5,8,7],[0,9,0]]
Output: 24
Explanation:
[[0,6,0],
 [5,8,7],
 [0,9,0]]
Path to get the maximum gold, 9 -> 8 -> 7.

Example 2:
Input: grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
Output: 28
Explanation:
[[1,0,7],
 [2,0,6],
 [3,4,5],
 [0,3,0],
 [9,0,20]]
Path to get the maximum gold, 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7.
 

Constraints:

1 <= grid.length, grid[i].length <= 15
0 <= grid[i][j] <= 100
There are at most 25 cells containing gold.
*/

//solution
class Solution {
    vector<vector<int>> mgrid;
    //vector<vector<int>> cache;
    int row, col;
    int maxG = INT_MIN;
public:
    bool isValid(int x, int y){
        if(x >= 0 && x < row && y >= 0 && y < col && mgrid[x][y] != -1 && mgrid[x][y] != 0)
            return true;
        return false;
    }
    
    bool cantMove(int x, int y){
        if(!isValid(x-1,y) && !isValid(x,y+1) && !isValid(x+1, y) && !isValid(x,y-1))
            return true;
        return false;
    }
    
    void process(int x, int y, int sum){
        if(!isValid(x, y))
            return;
        
        //cout<<x<<" "<<y<<endl;
        int temp = mgrid[x][y];
        mgrid[x][y] = -1;
        sum += temp;
        
        if(cantMove(x,y)){
            maxG = max(maxG, sum);
            mgrid[x][y] = temp;
            return;
        }
        
        process(x-1,y,sum);
        process(x,y+1,sum);
        process(x+1,y,sum);
        process(x,y-1,sum);
        
        mgrid[x][y] = temp;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        mgrid = move(grid);
        row = mgrid.size();
        col = mgrid[0].size();
        //cache.resize(row, vector<int>(col, -1));
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
                process(i,j,0);
        return maxG;
    }
};