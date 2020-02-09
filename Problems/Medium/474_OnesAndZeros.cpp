/*
In the computer world, use restricted resource you have to generate maximum 
benefit is what we always want to pursue.

For now, suppose you are a dominator of m 0s and n 1s respectively.
 On the other hand, there is an array with strings consisting of only 0s and 1s.

Now your task is to find the maximum number of strings that you can form 
with given m 0s and n 1s. Each 0 and 1 can be used at most once.

Note:

The given numbers of 0s and 1s will both not exceed 100
The size of given string array won't exceed 600.
 

Example 1:

Input: Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
Output: 4

Explanation: This are totally 4 strings can be formed by the using 
of 5 0s and 3 1s, which are “10,”0001”,”1”,”0”
 

Example 2:

Input: Array = {"10", "0", "1"}, m = 1, n = 1
Output: 2

Explanation: You could form "10", but then you'd have nothing left. 
Better form "0" and "1".
*/

//solution
class Solution {
    vector<string> mstrs;
    int cache[615][115][115];
    int zeros;
    int ones;
    int size;
public:
    void findOandZ(string& str, int& ones, int& zeros){
        for(auto ch : str){
            if(ch == '0')zeros++;
            if(ch == '1')ones++;
        }
    }
    
    int findMaxUtil(int index, int nones, int nzeros){
        if(index >= size){
            if(nones >= 0 && nzeros >= 0)
                return 0;
            return INT_MIN;
        }
        
        if(nones < 0 || nzeros < 0)
            return INT_MIN;
        
        if(cache[index][nones][nzeros] != -1)
            return cache[index][nones][nzeros];
        
        int c1 = findMaxUtil(index+1, nones, nzeros);

        int ones = 0, zeros = 0;
        findOandZ(mstrs[index], ones, zeros);
        int c2 = 1 + findMaxUtil(index+1, nones - ones, nzeros - zeros);
        return cache[index][nones][nzeros] = max(c1, c2);
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        mstrs = move(strs);
        zeros = m;
        ones = n;
        size = mstrs.size();
        for(int i = 0; i < 615; i++){
            for(int j = 0; j < 115; j++){
                for(int k = 0; k < 115; k++){
                    cache[i][j][k]=-1;
                }
            }
        }
        return findMaxUtil(0, ones, zeros);
    }
};