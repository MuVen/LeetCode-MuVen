/*
You are given coins of different denominations and a total amount of money 
amount. Write a function to compute the fewest number of coins that you need to 
make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:

Input: coins = [1, 2, 5], amount = 11
Output: 3 
Explanation: 11 = 5 + 5 + 1

Example 2:

Input: coins = [2], amount = 3
Output: -1
*/

//solution
class Solution {
    vector<int> coinsv;
    vector<vector<int>> cache;
public:
    int coinChangeUtil(int index, int amount){
        if(index < 0 || amount < 0)
            return INT_MAX-1;

        if(amount == 0)
            return 0;
        
        if(cache[index][amount] != -1)
            return cache[index][amount];

        int v1 = 1 + coinChangeUtil(index, amount - coinsv[index]);
        int v2 = coinChangeUtil(index-1, amount);
        return cache[index][amount] = min(v1,v2);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        coinsv = move(coins);
        cache.resize(coinsv.size()+2, vector<int>(amount+2, -1));
        int ans = coinChangeUtil(coinsv.size()-1, amount);
        return ans == INT_MAX-1 ? -1 : ans;
    }
};