/*
Given an array of integers arr, you are initially positioned at the first 
index of the array.

In one step you can jump from index i to index:

i + 1 where: i + 1 < arr.length.
i - 1 where: i - 1 >= 0.
j where: arr[i] == arr[j] and i != j.
Return the minimum number of steps to reach the last index of the array.

Notice that you can not jump outside of the array at any time.

 

Example 1:

Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
Output: 3
Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. 
Note that index 9 is the last index of the array.
Example 2:

Input: arr = [7]
Output: 0
Explanation: Start index is the last index. You don't need to jump.
Example 3:

Input: arr = [7,6,9,6,9,6,9,7]
Output: 1
Explanation: You can jump directly from index 0 to index 7 
which is last index of the array.
Example 4:

Input: arr = [6,1,9]
Output: 2
Example 5:

Input: arr = [11,22,7,7,7,7,7,7,7,22,13]
Output: 3
 

Constraints:

1 <= arr.length <= 5 * 10^4
-10^8 <= arr[i] <= 10^8
*/

//solution
class Solution {
    unordered_map<int, vector<int>> map;
    queue<pair<int, int>> que;
    vector<bool> visited;
public:
    int minJumps(vector<int>& arr) {
        visited.resize(arr.size(), false);
        for(int i = 0; i < arr.size(); i++){
//optimization;
/*
So, there can be alot of repetitions in the array and we can 
make too many pushes to the queue, to avoid such cases, we do the following.
For example the array is : [7,7,7......7,7,11] then instead of pushing 
indices of every occurence of 7 for 7, we will only push the first 
and the last index in case of such subarrays containing all same elements.
*/
            if(i > 0 && i < arr.size()-1 && arr[i] == arr[i-1] && arr[i] == arr[i+1])
                continue;
            map[arr[i]].push_back(i);
        }
        
        que.push({0,0});
        while(!que.empty()){
            auto p = que.front();que.pop();
            int index = p.first;
            int level = p.second;
            
            visited[index] = true;
            if(index == arr.size()-1)
                return level;
            
            if(index - 1 >= 0 && visited[index-1] == false){
                que.push({index-1, level+1});    
            }
            
            if(index + 1 < arr.size() && visited[index+1] == false){
                que.push({index+1, level+1});
            }
            
            vector<int> indexs = map[arr[index]];
            for(int i = 0; i < indexs.size(); i++){
                if(visited[indexs[i]] == false) {
                    que.push({indexs[i], level+1});
                }
            }
        }
        
        return 0;
    }
};