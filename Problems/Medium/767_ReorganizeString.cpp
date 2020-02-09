/*
Given a string S, check if the letters can be rearranged so that two characters 
that are adjacent to each other are not the same.

If possible, output any possible result.  If not possible, return the empty string.

Example 1:

Input: S = "aab"
Output: "aba"
Example 2:

Input: S = "aaab"
Output: ""
Note:

S will consist of lowercase letters and have length in range [1, 500].
*/

//solution
class Solution {
    unordered_map<char, int> map;
    priority_queue<pair<int,char>> que;
    int N;
public:
    string reorganizeString(string S) {
        N = S.length();
        for(auto ch : S)
            map[ch]++;
        for(auto m : map){
            if(m.second > (N+1)/2)
                return "";
            que.push({m.second, m.first});
        }
        
        cout<<que.size()<<endl;
        string ans;
        while(!que.empty()){
            auto fchar = que.top();que.pop();
            if(fchar.first){
                ans += fchar.second;
                fchar.first--;
            }
            //cout<<"1 "<<fchar.first<<" "<<fchar.second<<endl;
            if(!que.empty()){
                auto schar = que.top(); que.pop();
                if(schar.first){
                    ans += schar.second;
                    schar.first--;
                }
                //cout<<"2 "<<schar.first<<" "<<schar.second<<endl;
                if(schar.first)
                    que.push(schar);
            }
            if(fchar.first)
                que.push(fchar);
        }
        
        return ans;
    }
};