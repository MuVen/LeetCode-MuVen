/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, 
where "adjacent" cells are those horizontally or vertically neighboring. 
The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
*/

//solution
int xM[4]={-1,0,1,0};
int yM[4]={0,1,0,-1};

class Solution {
    vector<vector<char>> mboard;
    string fword;
    int ssize;
    int row, col;
public:
    inline bool isValid(int x, int y, int index){
        if(x >= 0 && x < row && y >= 0 && y < col && mboard[x][y] != '*')
            return true;
        return false;
    }
    
    bool find(int x, int y, int index){
        if(!isValid(x, y, index))
            return false;
        
        if(mboard[x][y] != fword[index])
             return false;
        
        if(index == ssize-1)
            return true;
        
        char temp = mboard[x][y];
        mboard[x][y] = '*';
        for(int i = 0; i < 4; i++){
            int nx = x + xM[i];
            int ny = y + yM[i];
            if(find(nx, ny, index+1))
                return true;
        }
        
        mboard[x][y] = temp;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        mboard = move(board);
        fword = move(word);
        row = mboard.size();
        col = mboard[0].size();
        ssize = fword.size();
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(fword[0] == mboard[i][j]){
                    if(find(i, j, 0))
                        return true;
                }
            }
        }
        
        return false;
    }
};