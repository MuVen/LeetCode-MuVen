/*
Given a 2D integer matrix M representing the gray scale of an image, you need to
 design a smoother to make the gray scale of each cell becomes the average 
 gray scale (rounding down) of all the 8 surrounding cells and itself. 
 If a cell has less than 8 surrounding cells, then use as many as you can.

Example 1:
Input:
[[1,1,1],
 [1,0,1],
 [1,1,1]]
Output:
[[0, 0, 0],
 [0, 0, 0],
 [0, 0, 0]]
Explanation:
For the point (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
For the point (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0
For the point (1,1): floor(8/9) = floor(0.88888889) = 0
Note:
The value in the given matrix is in the range of [0, 255].
The length and width of the given matrix are in the range of [1, 150].
*/

//solution
class Solution {
	int row, col;
	vector<vector<int>> grid;
	vector<vector<int>> res;
public:
	bool isValid(int& x, int& y) {
		if (x >= 0 && x < row && y >= 0 && y < col)
			return true;
		return false;
	}
	vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
		grid = move(M);

		int x[] = { 1, 1, 1, -1, -1, -1, 0, 0 };
		int y[] = { 1, -1, 0, 1, -1, 0, 1, -1 };
		row = grid.size();
		if (row == 0)
			return res;

		col = grid[0].size();

		res.resize(row, vector<int>(col, 0));
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {

				int value = grid[i][j];
				int count = 1;
				for (int k = 0; k < 8; k++) {
					int nx = i + x[k];
					int ny = j + y[k];
					if (isValid(nx, ny)) {
						value += grid[nx][ny];
						count++;
					}
				}

				res[i][j] = value / count;
			}
		}

		return move(res);
	}
};