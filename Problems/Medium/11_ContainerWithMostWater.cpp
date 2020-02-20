/*
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n
vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines,
which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. 
In this case, the max area of water (blue section) the container can contain is 49.

Example:

Input: [1,8,6,2,5,4,8,3,7]
Output: 49
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int first = 0, last = height.size()-1;
        int ans = INT_MIN;
        
        int minvalue, indexdiff, watersaved;
        while(first < last){
            //typical two pointer solution kindof;
            //take two height, first and last;
            //take the minimum height and calculate the index difference.
            //total water saved will be min height * index difference;
            //move the min height pointer;
            minvalue = min(height[first], height[last]);
            indexdiff = last - first;
            watersaved = minvalue * indexdiff;
            //cout<<minvalue<<" "<<indexdiff<<" "<<watersaved<<endl;
            if(minvalue == height[first])
                first++;
            else
                last--;
            ans = max(ans, watersaved);
        }
        return ans;
    }
};