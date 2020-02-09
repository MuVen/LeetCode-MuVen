/*
Given a m * n matrix mat of integers, sort it diagonally in ascending order 
from the top-left to the bottom-right then return the sorted array.


Example 1:

Input: mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
Output: [[1,1,1,1],[1,2,2,2],[1,2,3,3]]
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 100
1 <= mat[i][j] <= 100
*/

//solution
class Solution {
    unordered_map<int, priority_queue<int,vector<int>, greater<int>>> map;
    int m,n;
public:
    //i-j gives the diagonal elements in the matrix;
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();
        for(int i = 0; i < m; i++){
            for(int j  = 0; j < n; j++){
                map[i-j].push(mat[i][j]);
            }
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                mat[i][j] = map[i-j].top();map[i-j].pop();
            }
        }
        
        return mat;
    }
};