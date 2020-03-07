/*
Given an integer n, return any array containing n unique integers such
 that they add up to 0.

 

Example 1:

Input: n = 5
Output: [-7,-1,1,3,4]
Explanation: These arrays also are accepted [-5,-1,1,2,3] , [-3,-1,2,-2,4].
Example 2:

Input: n = 3
Output: [-1,0,1]
Example 3:

Input: n = 1
Output: [0]
 

Constraints:

1 <= n <= 1000
*/

//solution
class Solution {
public:
    vector<int> sumZero(int n) {
        if(n == 0 || n == 1)
            return vector<int>{0};
        vector<int> res;
        for(int i = 0; i <= n/2; i++){
            if(n%2 != 0){
                if(i == 0)
                    res.push_back(i);
                else{
                    res.push_back(i);
                    res.push_back(-i);
                }
            }else{
                if(i != 0){
                    res.push_back(i);
                    res.push_back(-i);
                }
            }
        }
        return res;
    }
};