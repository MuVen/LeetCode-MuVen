/*
In a given grid, each cell can have one of three values:

the value 0 representing an empty cell;
the value 1 representing a fresh orange;
the value 2 representing a rotten orange.
Every minute, any fresh orange that is adjacent (4-directionally) to a 
rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a
 fresh orange.  If this is impossible, return -1 instead.

 

Example 1:



Input: [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation:  The orange in the bottom left corner (row 2, column 0)
 is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: [[0,2]]
Output: 0
Explanation:  Since there are already no fresh oranges at minute 0, the answer is just 0.
 

Note:

1 <= grid.length <= 10
1 <= grid[0].length <= 10
grid[i][j] is only 0, 1, or 2.
*/

//solution
int xM[4] = { -1, 0, 1, 0 };
int yM[4] = { 0, 1, 0, -1 };

class Solution {
	vector<vector<int>> mgrid;
	queue<int> rotten;
	int row, col;
	int fresh;
public:
	bool isValid(int x, int y){
		if (x >= 0 && x < row && y >= 0 && y < col && mgrid[x][y] == 1)
			return true;
		return false;
	}

	int process(){
		if (fresh == 0)
			return 0;

		int count = 0;
		while (!rotten.empty()){
			count++;
			int size = rotten.size() / 2;
			while (size--){
				int x1 = rotten.front(); rotten.pop();
				int y1 = rotten.front(); rotten.pop();
				for (int d = 0; d < 4; d++){
					int nx = x1 + xM[d];
					int ny = y1 + yM[d];
					if (isValid(nx, ny)){
						rotten.push(nx);
						rotten.push(ny);
						mgrid[nx][ny] = 2;
						fresh--;
					}
				}
			}
		}

		return fresh == 0 ? count - 1 : -1;
	}


	int orangesRotting(vector<vector<int>>& grid) {
		row = grid.size();
		col = grid[0].size();
		for (int i = 0; i < row; i++){
			for (int j = 0; j < col; j++){
				if (grid[i][j] == 2){
					rotten.push(i);
					rotten.push(j);
				}
				else if (grid[i][j] == 1){
					fresh++;
				}
			}
		}
		mgrid = move(grid);
		return process();
	}
};