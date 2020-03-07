/*
An image is represented by a 2-D array of integers, each integer
 representing the pixel value of the image (from 0 to 65535).

Given a coordinate (sr, sc) representing the starting pixel 
(row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, 
plus any pixels connected 4-directionally to the starting pixel of the 
same color as the starting pixel, plus any pixels connected 4-directionally
 to those pixels (also with the same color as the starting pixel),
 and so on. Replace the color of all of the aforementioned pixels with the newColor.

At the end, return the modified image.

Example 1:
Input: 
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: 
From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected 
by a path of the same color as the starting pixel are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected
to the starting pixel.
Note:

The length of image and image[0] will be in the range [1, 50].
The given starting pixel will satisfy 0 <= sr < image.length and 0 <= sc < image[0].length.
The value of each color in image[i][j] and newColor will be an integer in [0, 65535].
*/

//solution
class Solution {
	vector<vector<int>> res;
	vector<vector<int>> vis;
	int row, col, valcol, newcol;
public:

	bool isvalid(int x, int y){
		if (x >= 0 && x <= row - 1 && y >= 0 && y <= col - 1 && res[x][y] == valcol && vis[x][y] == 0)
			return true;
		return false;
	}

	void fill(int sr, int sc){
		if (!isvalid(sr, sc))
			return;

		res[sr][sc] = newcol;
		vis[sr][sc] = 9;

		fill(sr - 1, sc);
		fill(sr + 1, sc);
		fill(sr, sc - 1);
		fill(sr, sc + 1);
	}

	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
		res = move(image);
		row = res.size();
		if (row == 0)
			return vector<vector<int>>{};
		col = res[0].size();
		vis.resize(row, vector<int>(col, 0));
		valcol = res[sr][sc];
		newcol = newColor;
		fill(sr, sc);
		return move(res);
	}
};