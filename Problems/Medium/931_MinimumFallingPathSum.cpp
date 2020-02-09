/*
Given a square array of integers A, we want the minimum sum of a falling path 
through A.

A falling path starts at any element in the first row, and chooses one element 
from each row.  The next row's choice must be in a column that is different 
from the previous row's column by at most one.

Example 1:

Input: [[1,2,3],[4,5,6],[7,8,9]]
Output: 12
Explanation: 
The possible falling paths are:
[1,4,7], [1,4,8], [1,5,7], [1,5,8], [1,5,9]
[2,4,7], [2,4,8], [2,5,7], [2,5,8], [2,5,9], [2,6,8], [2,6,9]
[3,5,7], [3,5,8], [3,5,9], [3,6,8], [3,6,9]
The falling path with the smallest sum is [1,4,7], so the answer is 12.

Note:

1 <= A.length == A[0].length <= 100
-100 <= A[i][j] <= 100
*/

//solution
#define MIN(a,b) ((a)>(b)?(b):(a))

class Solution {
	vector<vector<int>> CA;
	vector<vector<int>> cache;
	int rows, cols;
	int ans;
	const int inf = 1e8;
public:

	int go(int x, int y){
		if (x == rows)
			return 0;

		if (y < 0 || y >= cols)
			return inf;

		if (cache[x][y] != -1)
			return cache[x][y];

		int ans = INT_MAX;
		int& cval = CA[x][y];

		//case 1: x+1, y
		ans = MIN(cval + go(x + 1, y), ans);

		//case 2: x+1, y-1
		ans = MIN(cval + go(x + 1, y - 1), ans);

		//case 3: x+1, y+1
		ans = MIN(cval + go(x + 1, y + 1), ans);

		return cache[x][y] = ans;
	}

	int minFallingPathSum(vector<vector<int>>& A) {
		ans = INT_MAX;
		CA = move(A);
		rows = CA.size();
		cols = CA[0].size();

		cache.resize(rows);
		for (int i = 0; i < rows; i++){
			cache[i].resize(cols, -1);
		}
		
		for (int i = 0; i < cols; i++){
			ans = MIN(ans, go(0, i));
		}
		return ans;
	}
};