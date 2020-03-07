/*
Given n points in the plane that are all pairwise distinct, a "boomerang" is a
 tuple of points (i, j, k) such that the distance between i and j equals the
 distance between i and k (the order of the tuple matters).

Find the number of boomerangs. You may assume that n will be at most 500 and 
coordinates of points are all in the range [-10000, 10000] (inclusive).

Example:

Input:
[[0,0],[1,0],[2,0]]

Output:
2

Explanation:
The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
*/

//solution
class Solution {
    int ans = 0;
public:
    int distance(vector<int>& p1, vector<int>& p2){
        return ((p2[0]-p1[0])*(p2[0]-p1[0]) + (p2[1]-p1[1])*(p2[1]-p1[1]));
    }
    
    void findBoomerangs(vector<int>& p1, vector<int>& p2, vector<int>& p3){
        int d12 = distance(p1,p2);
        int d13 = distance(p1,p3);
        int d23 = distance(p2,p3);
        
        if(d12 == d13)ans+=2;
        if(d12 == d23)ans+=2;
        if(d13 == d23)ans+=2;
    }
    
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int size = points.size();
        for(int i = 0; i < size-2; i++){
            for(int j = i+1; j < size-1; j++){
                for(int z = j+1; z < size; z++){
                    findBoomerangs(points[i], points[j], points[z]);    
                }
            }
        }
        return ans;
    }
};