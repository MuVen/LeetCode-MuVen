/*
Given a 2D binary matrix filled with 0's and 1's, 
find the largest square containing only 1's and return its area.

Example:

Input: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4
*/

//solution
#define minv(a,b) ((a)>(b)?(b):(a))
#define maxv(a,b) ((a)>(b)?(a):(b))

int mymin(int x, int y, int z){
    return minv(minv(x,y),z);
}

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> smatrix;
        int row = matrix.size();
        
        if(row == 0)
            return 0;
        
        int col = matrix[0].size();
        int amax = INT_MIN;
        smatrix.resize(row, vector<int>(col,0));
        for(int i = 0; i < row; i++){
            smatrix[i][0] = matrix[i][0]-'0';
            amax = maxv(amax, smatrix[i][0]);
        }
            
        for(int j = 0; j < col; j++){
            smatrix[0][j] = matrix[0][j]-'0';
            amax = maxv(amax, smatrix[0][j]);
        }
            
        for(int i = 1; i < row; i++){
            for(int j = 1; j < col; j++){
                if(matrix[i][j] == '0')
                    smatrix[i][j] = 0;
                else 
                    smatrix[i][j] = mymin(smatrix[i-1][j], smatrix[i][j-1], smatrix[i-1][j-1]) +1;
                amax = maxv(amax, smatrix[i][j]);
            }
        }
        
        return amax * amax;
    }
};