/*
528. Random Pick with Weight

Given an array w of positive integers, where w[i] describes the weight of index i, write 
a function pickIndex which randomly picks an index in proportion to its weight.

Note:

1 <= w.length <= 10000
1 <= w[i] <= 10^5
pickIndex will be called at most 10000 times.
Example 1:

Input: 
["Solution","pickIndex"]
[[[1]],[]]
Output: [null,0]
Example 2:

Input: 
["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
[[[1,3]],[],[],[],[],[]]
Output: [null,0,1,1,1,0]
Explanation of Input Syntax:

The input is two lists: the subroutines called and their arguments. Solution's constructor 
has one argument, the array w. pickIndex has no arguments. Arguments are always wrapped 
with a list, even if there aren't any.

*/
class Solution {
    vector<int> val;
public:
    Solution(vector<int>& w) {
        double sum = 0;
        for(int i = 0; i < w.size(); i++)
            sum += w[i];

        //distribute weight evenly
        /*
            [1,3] 1 value is 25 % 1/4
                  3 value is 75 % 3/4
            25% of the time we have to pick 1, 
            75% of the time we have to pick 3
        */
        
        for(int i = 0; i < w.size(); i++){
            int count = ceil((w[i]/sum)*100);
            //cout<<count<<endl;
            for(int j = 0; j < count; j++)val.push_back(i);
        }
        
        /*for(auto v : val)
            cout<<v<<" ";
        cout<<endl;*/
    }
    
    int pickIndex() {
        return val[rand()%val.size()];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */