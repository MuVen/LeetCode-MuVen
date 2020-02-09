/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of 
islands. An island is surrounded by water and is formed by connecting 
adjacent lands horizontally or vertically. You may assume all four edges
 of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1

Example 2:

Input:
11000
11000
00100
00011

Output: 3
*/

//solution
class Solution {
    vector<vector<char>> grida;
    int row, col;
public:
    bool isValid(int x, int y){
        if(x < 0 || x >= row || y < 0 || y >= col || grida[x][y] == '9' || grida[x][y] == '0')
            return false;
        return true;
    }
    void floodfill(int x, int y){
        if(!isValid(x,y))
            return;
        
        grida[x][y] = '9';
        floodfill(x+1,y);
        floodfill(x-1,y);
        floodfill(x,y+1);
        floodfill(x,y-1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0)
            return 0;
        
        grida = move(grid);
        
        row = grida.size();
        col = grida[0].size();
        
        int count = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grida[i][j] == '1'){
                    floodfill(i,j);
                    count++;
                }
            }
        }
        
        return count;
    }
};