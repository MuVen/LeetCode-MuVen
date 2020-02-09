/*
Given a matrix of m x n elements (m rows, n columns), return all 
elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/

//solution
class Solution {
    enum {RIGHT = 0, DOWN, LEFT, UP};
    vector<int> res;
    vector<vector<int>> matrixd;
    vector<vector<bool>> visited;
    int row, col;
public:
    
    bool isValid(int x, int y){
        if(x < 0 || x >= row || y < 0 || y >= col || visited[x][y] == true)
            return false;
        return true;
    }
    
    void formSpiral(int x, int y, int dir){
        if(!isValid(x, y))
            return;
        
        res.push_back(matrixd[x][y]);
        visited[x][y] = true;

        if(dir == RIGHT){
            y = y + 1;
            if(isValid(x, y) == false){
                dir = DOWN;
                x = x + 1;
                y = y - 1;
            }
        }
        else if(dir == DOWN){
            x = x + 1;
            if(isValid(x, y) == false){
                dir = LEFT;
                x = x - 1;
                y = y - 1;
            }
        }
        else if(dir == LEFT){
            y = y - 1;
            if(isValid(x, y) == false){
                dir = UP;
                x = x - 1;
                y = y + 1;
            }
        }
        else if(dir == UP){
            x = x - 1;
            if(isValid(x, y) == false){
                dir = RIGHT;
                x = x + 1;
                y = y + 1;
            }
        }
        
        formSpiral(x, y, dir);
    }
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0)
            return res;
        
        int x = 0, y = 0;
        int dir = RIGHT;
        
        row = matrix.size();
        col = matrix[0].size();
        matrixd = move(matrix);
        
        visited.resize(row, vector<bool>(col, false));
        formSpiral(x, y, dir);
        return res;
    }
};