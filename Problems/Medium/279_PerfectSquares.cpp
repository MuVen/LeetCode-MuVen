/*
Given a positive integer n, find the least number of perfect square numbers 
(for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3 
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
*/
//solution
class Solution {
    vector<int> squares;
    vector<vector<int>> cache;
public:
    int findMin(int index, int targetSum){
        if(index < 0 || targetSum < 0)
            return INT_MAX-1;
        
        if(targetSum == 0)
            return 0;

        if(cache[index][targetSum] != -1)
            return cache[index][targetSum];

        int v1 = 1 + findMin(index, targetSum-squares[index]);
        int v2 = findMin(index-1, targetSum);
        return cache[index][targetSum] = min(v1, v2);
    }
    
    int numSquares(int n) {
        for(int i = 1; ; i++){
            if(i*i > n)
                break;
            squares.push_back(i*i);
        }
        
        cache.resize(squares.size()+2, vector<int>(n+2, -1));
        return findMin(squares.size()-1, n);
    }
};