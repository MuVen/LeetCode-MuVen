/*
Given n non-negative integers representing an elevation map where the width 
of each bar is 1, compute how much water it is able to trap after raining.

The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 

In this case, 6 units of rain water (blue section) are being trapped. 
Thanks Marcos for contributing this image!

Example:
Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
*/

//solution
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)>(b)?(b):(a))
#define ABS(a,b) ((a)>(b)?(a-b):(b-a))

class Solution {
	vector<int> lmax;
	vector<int> rmax;
	int hsize;
public:
	int trap(vector<int>& height) {
		hsize = height.size();
		if (hsize == 0)
			return 0;

		lmax.push_back(height[0]);
		for (int i = 1; i < hsize; i++){
			int mval = max(height[i], lmax[i - 1]);
			lmax.push_back(mval);
		}

		rmax.resize(hsize, 0);
		rmax[hsize - 1] = height[hsize - 1];
		for (int i = hsize - 2; i >= 0; i--){
			int mval = max(height[i], rmax[i + 1]);
			rmax[i] = mval;
		}
		
		int ans = 0;
		for (int i = 0; i < hsize; i++){
			int mval = min(lmax[i], rmax[i]);
			ans += ABS(height[i] , mval);
		}
		return ans;
	}
};