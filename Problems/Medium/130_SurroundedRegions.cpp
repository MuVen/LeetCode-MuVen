/*
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
Explanation:

Surrounded regions shouldn’t be on the border, which means that any 'O' on the 
border of the board are not flipped to 'X'. Any 'O' that is not on the border 
and it is not connected to an 'O' on the border will be flipped to 'X'. 
Two cells are connected if they are adjacent cells connected horizontally
or vertically.
*/

//solution
class Solution {
    int row,col;
    vector<vector<char>> mboard;
public:
    void check(int x, int y){
        if(x < 0 || x >= row || y < 0 || y >= col || mboard[x][y]=='X' || mboard[x][y] == 9)
            return;
        
        mboard[x][y] = 9;
        check(x-1,y);
        check(x, y+1);
        check(x+1,y);
        check(x, y-1);
    }
    
    void solve(vector<vector<char>>& board) {
        row = board.size();
        if(row == 0)
            return;
        col = board[0].size();
        mboard = move(board);
        for(int i = 0; i < col; i++){
             check(0, i);
             check(row-1, i);
        }
        for(int i = 0; i < row; i++){
            check(i,0);
            check(i, col-1);
        }
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(mboard[i][j] == 9)
                    mboard[i][j]='O';
                else
                    mboard[i][j]='X';
            }
        }
        board = move(mboard);
    }
};