/*
Given a char array representing tasks CPU need to do. It contains capital 
letters A to Z where different letters represent different tasks. Tasks could be
 done without original order. Each task could be done in one interval. 
 For each interval, CPU could finish one task or just be idle.

However, there is a non-negative cooling interval n that means between two same
 tasks, there must be at least n intervals that CPU are doing different tasks
 or just be idle.

You need to return the least number of intervals the CPU will take to finish 
all the given tasks.

Example:

Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
 

Note:

The number of tasks is in the range [1, 10000].
The integer n is in the range [0, 100].
*/

//solution
class Solution {
    unordered_map<char, int> map;
    priority_queue<pair<int, char>> que;
public:
    int leastInterval(vector<char>& tasks, int n) {
        for(auto ch : tasks)
            map[ch]++;
        for(auto m : map)
            que.push({m.second, m.first});
        
        int ans = 0;
        while(!que.empty()){
            int cooldown = n+1;
            vector<pair<int, int>> vec;
            while(cooldown--){
                if(!que.empty()){
                    pair<int,char> p = que.top();que.pop();
                    if(p.first > 0){
                        p.first--;
                        ans += 1;
                        if(p.first > 0)
                            vec.push_back(move(p));
                    }
                }else{
                    if(vec.size() > 0)
                        ans += 1;//'#';
                }
            }
            for(auto v : vec)
                que.push(v);
        }

        return ans;
    }
};