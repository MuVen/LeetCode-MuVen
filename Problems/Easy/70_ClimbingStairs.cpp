/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways 
can you climb to the top?

Note: Given n will be a positive integer.

Example 1:

Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
*/

//solution
class Solution {
    vector<int> cache;
public:
    int climbStairsUtil(int n) {
        if(n == 0)
            return 1;
        if(n < 0)
            return 0;
        if(cache[n] != -1)
            return cache[n];
        return cache[n] = climbStairsUtil(n-1) + climbStairsUtil(n-2);
    }
    
    int climbStairs(int n){
        cache.resize(n+10, -1);
        return climbStairsUtil(n);
    }
};