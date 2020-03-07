/*
You have a list of points in the plane. Return the area of the largest 
triangle that can be formed by any 3 of the points.

Example:
Input: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
Output: 2
Explanation: 
The five points are show in the figure below. The red triangle is the largest.


Notes:

3 <= points.length <= 50.
No points will be duplicated.
 -50 <= points[i][j] <= 50.
Answers within 10^-6 of the true value will be accepted as correct.
*/

//solution
class Solution {
public:
    
    double largestTriangleArea(vector<vector<int>>& points) {
        double ans = 0;
        int size = points.size();
        for(int i = 0; i < size; i++){
            for(int j = i + 1; j < size; j++){
                for(int k = j + 1; k < size; k++){
                    double p1x = points[i][0], p1y = points[i][1];
                    double p2x = points[j][0], p2y = points[j][1];
                    double p3x = points[k][0], p3y = points[k][1];
                    double tarea = abs((p1x*(p2y-p3y)) + (p2x*(p3y-p1y)) + (p3x*(p1y-p2y))) / 2;
                    ans = max(ans, tarea);
                }
            }
        }
        return ans;
    }
};