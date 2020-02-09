/*
Given a positive integer n and you can do operations as follow:

If n is even, replace n with n/2.
If n is odd, you can replace n with either n + 1 or n - 1.
What is the minimum number of replacements needed for n to become 1?

Example 1:

Input:
8

Output:
3

Explanation:
8 -> 4 -> 2 -> 1
Example 2:

Input:
7

Output:
4

Explanation:
7 -> 8 -> 4 -> 2 -> 1
or
7 -> 6 -> 3 -> 2 -> 1
*/

//solution
class Solution {
public:
    int integerReplacement(int n) {        
        queue<vector<long long int>> q;
        q.push({n,0});
        while(!q.empty()){
            auto v = q.front();q.pop();
            cout<<v[0]<<" "<<v[1]<<endl;
            if(v[0]==1)
                return v[1];
            if(v[0]%2==0){
                q.push({v[0]>>1, v[1]+1});
            }else{
                q.push({v[0]+1, v[1]+1});
                q.push({v[0]-1, v[1]+1});
            }
        }
        return 0;
    }
};