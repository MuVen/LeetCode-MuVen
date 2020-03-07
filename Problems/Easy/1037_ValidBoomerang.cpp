/*
A boomerang is a set of 3 points that are all distinct and not in a straight line.

Given a list of three points in the plane, return whether these points are a boomerang.

 

Example 1:

Input: [[1,1],[2,3],[3,2]]
Output: true
Example 2:

Input: [[1,1],[2,2],[3,3]]
Output: false
 

Note:

points.length == 3
points[i].length == 2
0 <= points[i][j] <= 100
 
*/

//solution
class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {      
        int yadiff = points[1][1]-points[0][1];
        int xadiff = points[1][0]-points[0][0];
        
        int ybdiff = points[2][1]-points[1][1];
        int xbdiff = points[2][0]-points[1][0];
        
        return !(yadiff*xbdiff == ybdiff*xadiff); 
    }
};