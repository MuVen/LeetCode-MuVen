/*
You have n binary tree nodes numbered from 0 to n - 1 where node i has two children leftChild[i] and rightChild[i], return true if and only if all the given nodes form exactly one valid binary tree.

If node i has no left child then leftChild[i] will equal -1, similarly for the right child.

Note that the nodes have no values and that we only use the node numbers in this problem.

 

Example 1:



Input: n = 4, leftChild = [1,-1,3,-1], rightChild = [2,-1,-1,-1]
Output: true
Example 2:



Input: n = 4, leftChild = [1,-1,3,-1], rightChild = [2,3,-1,-1]
Output: false
Example 3:



Input: n = 2, leftChild = [1,0], rightChild = [-1,-1]
Output: false
Example 4:



Input: n = 6, leftChild = [1,-1,-1,4,-1,-1], rightChild = [2,-1,-1,5,-1,-1]
Output: false
 

Constraints:

1 <= n <= 10^4
leftChild.length == rightChild.length == n
-1 <= leftChild[i], rightChild[i] <= n - 1
*/

class Solution {
    unordered_map<int, vector<int>> map;
    vector<bool> visited;
    
public:
    bool bfs(int node){
        queue<int> que;
        que.push(node);
        while(!que.empty()){
            int cnode = que.front(); que.pop();
            if(visited[cnode] == true)
                return false;
            visited[cnode] = true;   
            if(map.find(cnode) != map.end()){
                vector<int> links = map[cnode];
                for(int i = 0; i < links.size(); i++)
                    que.push(links[i]);
            }
        }
        
        return true;
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        visited.resize(n, false);
        for(int i = 0; i < n; i++){
            if(leftChild[i] != -1)
                map[i].push_back(leftChild[i]);
            if(rightChild[i] != -1)
                map[i].push_back(rightChild[i]);
        }
        
        if(bfs(0) == false)
            return false;
        
        for(int i = 0; i < n; i++){
            if(visited[i] == false)
                return false;
        }
        
        return true;
    }
};