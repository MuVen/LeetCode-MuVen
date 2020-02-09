/*
Given an unsorted array of integers, find the length of the longest 
consecutive elements sequence.

Your algorithm should run in O(n) complexity.

Example:

Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. 
Therefore its length is 4.
*/

//solution
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    vector<int> vec = move(nums);
    unordered_map<int, int> map;
	for (int i = 0; i < vec.size(); i++)
		map[vec[i]] = vec[i];

	queue<int> q;
	int ans = 0;
	while (1) {
		if (map.size() == 0)
			break;
		auto it = next(map.begin(), 0);
		int ele = it->first;
		q.push(ele);
		map.erase(map[ele]);
		int count = 0;
		while (!q.empty()) {
			int val = q.front(); q.pop();
			count++;
			if (map.find(val + 1) != map.end()) {
				q.push(val + 1);
				map.erase(map[val + 1]);
			}
			if (map.find(val - 1) != map.end()) {
				q.push(val - 1);
				map.erase(map[val - 1]);
			}
		}
		ans = count > ans ? count : ans;
	}

	return ans;  
    }
};