/*
Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's 
(representing land) connected 4-directionally (horizontal or vertical.)
 You may assume all four edges of the grid are surrounded by water.

Find the maximum area of an island in the given 2D array. 
(If there is no island, the maximum area is 0.)

Example 1:

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
Given the above grid, return 6. Note the answer is not 11, 
because the island must be connected 4-directionally.

Example 2:

[[0,0,0,0,0,0,0,0]]
Given the above grid, return 0.
Note: The length of each dimension in the given grid does not exceed 50.
*/
//solution
#define MAX(a,b) ((a)>(b)?(a):(b))

class Solution {
    int row, col;
    vector<vector<int>> gridc;
public:
    void island(int x, int y, int& count){
        if(x < 0 || x >= row || y < 0 || y >= col || gridc[x][y] == -1 || gridc[x][y] == 0)
            return;
        
        if(gridc[x][y])
            count++;
        
        gridc[x][y] = 0;        
        island(x-1,y,count);
        island(x+1,y,count);
        island(x,y-1,count);
        island(x,y+1,count);                
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        gridc = move(grid);

        if(row == 0)
            return 0;

        int ans = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                int count = 0;
                if(gridc[i][j] == 1)
                    island(i,j, count);
                //cout<<count<<" "<<ans<<endl;
                ans = MAX(ans, count);
            }
        }
        return ans;
    }
};