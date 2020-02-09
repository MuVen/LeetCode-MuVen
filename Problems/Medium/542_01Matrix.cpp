/*
Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

 

Example 1:

Input:
[[0,0,0],
 [0,1,0],
 [0,0,0]]

Output:
[[0,0,0],
 [0,1,0],
 [0,0,0]]
Example 2:

Input:
[[0,0,0],
 [0,1,0],
 [1,1,1]]

Output:
[[0,0,0],
 [0,1,0],
 [1,2,1]]
 

Note:

The number of elements of the given matrix will not exceed 10,000.
There are at least one 0 in the given matrix.
The cells are adjacent in only four directions: up, down, left and right.
*/

//solutionint xM[4]={-1,0,1,0};
int yM[4]={0,1,0,-1};
struct coords{
    int x, y;
};

class Solution {
    vector<vector<int>> dist;
    vector<vector<int>> mmatrix;
    int row, col;
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        row = matrix.size();
        if(row == 0)
            return vector<vector<int>> {};
        col = matrix[0].size();

        dist.resize(row, vector<int>(col, INT_MAX));
        
        queue<coords> que;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(matrix[i][j] == 0){
                    dist[i][j] = 0;
                    que.push({i,j});
                }
            }
        }
        
        while(!que.empty()){
            coords c = que.front();que.pop();
            for(int i = 0; i < 4; i++){
                int nx = c.x+xM[i];
                int ny = c.y+yM[i];
                if(nx >= 0 && nx < row && ny >= 0 && ny < col){
                    if(dist[nx][ny] > dist[c.x][c.y]+1){
                        dist[nx][ny] = dist[c.x][c.y] + 1;
                        que.push({nx, ny});
                    }
                }
            }
        }
        
        return dist;
    }
};