/*
A Tic-Tac-Toe board is given as a string array board. Return True if and
 only if it is possible to reach this board position during the course 
 of a valid tic-tac-toe game.

The board is a 3 x 3 array, and consists of characters " ", "X", and "O". 
 The " " character represents an empty square.

Here are the rules of Tic-Tac-Toe:

Players take turns placing characters into empty squares (" ").
The first player always places "X" characters, while the second player 
always places "O" characters."X" and "O" characters are always placed into 
empty squares, never filled ones.The game ends when there are 3 of the same 
(non-empty) character filling any row, column, or diagonal.The game also ends
if all squares are non-empty.No more moves can be played if the game is over.

Example 1:
Input: board = ["O  ", "   ", "   "]
Output: false
Explanation: The first player always plays "X".

Example 2:
Input: board = ["XOX", " X ", "   "]
Output: false
Explanation: Players take turns making moves.

Example 3:
Input: board = ["XXX", "   ", "OOO"]
Output: false

Example 4:
Input: board = ["XOX", "O O", "XOX"]
Output: true
Note:

board is a length-3 array of strings, where each string board[i] has length 3.
Each board[i][j] is a character in the set {" ", "X", "O"}.
*/

//solution
class Solution {
public:
    int cnt(vector<string>& board, char ch){
        int sum = 0;
        for(auto s : board)
            sum += count(s.begin(), s.end(), ch);
        return sum;
    }
    
    bool win(vector<string>& board, char ch){
        for(int i = 0; i < 3; i++){
            if(board[i][0] == ch && board[i][1] == ch && board[i][2] == ch)
                return true;
        }
        
        for(int i = 0; i < 3; i++){
            if(board[0][i] == ch && board[1][i] == ch && board[2][i] == ch)
                return true;
        }
        
        if(board[0][0] == ch && board[1][1] == ch && board[2][2] == ch)
            return true;
            
        if(board[0][2] == ch && board[1][1] == ch && board[2][0] == ch)
            return true;
        
        return false;
    }
    
    bool validTicTacToe(vector<string>& board) {
        int CX = cnt(board, 'X'),CO = cnt(board, 'O');
        bool WX = win(board, 'X'), WO = win(board, 'O');
        //if both x and o wins then its false.
        if(WX == true && WO == true)
            return false;
        //if x wins, then X count should be 1 more than O
        if(WX) return CX == CO + 1;
        //if o wins, then X and O shold be equal.
        if(WO) return CX == CO;
        //board state is true; if O + 1 is X or X == O
        return CX == CO + 1 || CX == CO;
    }
};