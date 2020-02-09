/*
Given a string, your task is to count how many palindromic substrings in 
this string.

The substrings with different start indexes or end indexes are counted as 
different substrings even they consist of same characters.

Example 1:

Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
 

Example 2:

Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

*/

//solution
class Solution {
	string cs;
	vector<vector<int>> cache;
public:
	int go(int i, int j){
		if (i > j) return 1;
		if (i == j) return 1;
		if (cs[i] != cs[j]) return 0;
		if (cache[i][j] != -1)return cache[i][j];
		return cache[i][j] = go(i + 1, j - 1);
	}

	int countSubstrings(string& s) {
		cs = move(s);
		int n = cs.size();
		cache.resize(n, vector<int>(n, -1));
		int ans = 0;
		for (int i = 0; i < n; i++){
			for (int j = i; j < n; j++){
				ans += go(i, j);
			}
		}
		return ans;
	}
};