/*
Write an efficient algorithm that searches for a value in an m x n matrix. 
This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
Example:

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.
*/
//solution
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size()-1;
        if(row < 0)
            return false;
        
        int col = matrix[0].size()-1;
        if(col < 0)
            return false;
        int srow = 0;
        int scol = col;
        while(1){
            if(srow > row || scol < 0)
                break;
            if(target == matrix[srow][scol])
                return true;
            else if(target > matrix[srow][scol]){
                srow++;
            }else {
                scol--;
            }
        }
        
        return false;
    }
};