/*
A robot on an infinite grid starts at point (0, 0) and faces north. 
 The robot can receive one of three possible types of commands:

-2: turn left 90 degrees
-1: turn right 90 degrees
1 <= x <= 9: move forward x units
Some of the grid squares are obstacles. 

The i-th obstacle is at grid point (obstacles[i][0], obstacles[i][1])

If the robot would try to move onto them, the robot stays on the previous 
grid square instead (but still continues following the rest of the route.)

Return the square of the maximum Euclidean distance that the robot will be from the origin.

 

Example 1:

Input: commands = [4,-1,3], obstacles = []
Output: 25
Explanation: robot will go to (3, 4)
Example 2:

Input: commands = [4,-1,4,-2,4], obstacles = [[2,4]]
Output: 65
Explanation: robot will be stuck at (1, 4) before turning left and going to (1, 8)
 

Note:

0 <= commands.length <= 10000
0 <= obstacles.length <= 10000
-30000 <= obstacle[i][0] <= 30000
-30000 <= obstacle[i][1] <= 30000
The answer is guaranteed to be less than 2 ^ 31.
*/

//solution
class Solution {
    set<pair<int,int>> mset;
    int x = 0, y = 0;
    int dir = 0;
    int ans = INT_MIN;
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        for(auto vec : obstacles)
            mset.insert({vec[0],vec[1]});

        for(auto c : commands){
            if(c == -1){
                dir = dir + 1;
                dir %= 4;
            }else if(c == -2){
                if(dir == 0)
                    dir = 3;
                else
                    dir = dir - 1;
            }else{
                int nx = x, ny = y;
                for(int i = 1; i <= c; i++){
                    if(dir == 0){
                        ny += 1;
                    }else if(dir == 1){
                        nx += 1;
                    }else if(dir == 2){
                        ny -= 1;
                    }else if(dir == 3){
                        nx -= 1;
                    }
                    if(mset.find({nx,ny}) == mset.end()){
                        x = nx; y = ny;
                    }else
                        break;
                }
                ans = max(ans, x*x+y*y);
            }
        }

        return ans;
    }
};