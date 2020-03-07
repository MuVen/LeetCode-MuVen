/*
You are given an array coordinates, coordinates[i] = [x, y], 
where [x, y] represents the coordinate of a point. 
Check if these points make a straight line in the XY plane.

 

 

Example 1:



Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true
Example 2:



Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false
 

Constraints:

2 <= coordinates.length <= 1000
coordinates[i].length == 2
-10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
coordinates contains no duplicate point.
*/

//solution
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates.size() == 0)
            return false;

        int x1 = coordinates[0][0], y1 = coordinates[0][1];
        int x2 = coordinates[1][0], y2 = coordinates[1][1];
        
        int ycoeff = (x2-x1);
        int xcoeff = (y2-y1) * -1;
        int k = ycoeff * y1 + xcoeff * x1;

        for(int i = 2; i < coordinates.size(); i++) {
            int x = coordinates[i][0], y = coordinates[i][1];
            if( ((ycoeff * y) + (xcoeff * x)) != k )
                return false;
        }

        return true;
    }
};t