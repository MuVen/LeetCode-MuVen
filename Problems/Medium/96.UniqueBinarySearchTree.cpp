/*
Given n, how many structurally unique BST's (binary search trees) 
that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

//solution
class Solution {
    vector<unsigned long long int> cache;
public:
    int catalan(unsigned long long int n){
        if(n <= 1)
            return 1;
        
        if(cache[n] != 0)
            return cache[n];
        
        unsigned long long int res = 0;
        for(int i = 0; i < n; i++)
            res += catalan(i)*catalan(n-i-1);
        return cache[n] = res;
    }
    
    int numTrees(int n) {
        cache.resize(n+1, 0);
        return catalan(n);
    }
};