/*
There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have 
to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, 
return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. 
If it is impossible to finish all courses, return an empty array.

Example 1:

Input: 2, [[1,0]] 
Output: [0,1]
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So the correct course order is [0,1] .

Example 2:

Input: 4, [[1,0],[2,0],[3,1],[3,2]]
Output: [0,1,2,3] or [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both     
             courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. 
             So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .
Note:

The input prerequisites is a graph represented by a list of edges, 
not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.

*/

//solution
class Solution {
	vector<vector<int>> grid;
	vector<bool> fvisited;
	vector<bool> recstack;
	stack<int> s;
	int nvertices;
	bool hascycle;
public:
	void dfs(int src){
		if (fvisited[src])
			return;
		if (hascycle)
			return;

		fvisited[src] = true;
		recstack[src] = true;
		for (int i = 0; i < nvertices; i++){
			if (fvisited[i] == true && grid[src][i] == 1 && recstack[i] == true){
				hascycle = true;
				return;
			}
			if (fvisited[i] == false && grid[src][i] == 1){
				dfs(i);
				if (hascycle)
					return;
			}
		}

		recstack[src] = false;
		s.push(src);
	}

	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		nvertices = numCourses;
		grid.resize(numCourses, vector<int>(numCourses, 0));
		for (int i = 0; i < prerequisites.size(); i++){
			int a = prerequisites[i][0];
			int b = prerequisites[i][1];
			grid[a][b] = 1;
		}

		fvisited.resize(numCourses, false);
		recstack.resize(numCourses, false);

		for (int i = 0; i < numCourses; i++){
			if (fvisited[i] == false){
				hascycle = false;
				dfs(i);
				if (hascycle)
					return vector<int>{};
			}
		}

		vector<int> result;
		int rindex = numCourses-1;
		result.resize(numCourses, 0);
		while (s.empty() == false){
			result[rindex--] = s.top();
			s.pop();
		}

		return result;
	}
};