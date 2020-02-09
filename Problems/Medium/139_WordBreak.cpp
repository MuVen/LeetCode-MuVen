/*
Given a non-empty string s and a dictionary wordDict containing a list of 
non-empty words, determine if s can be segmented into a space-separated 
sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as 
"apple pen apple".
             Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false
*/

//solution
class Solution {
	unordered_map<string, bool> map;
	unordered_map<string, bool> cache;
public:
	bool wordBreakUtil(string s){
		int size = s.length();
		if (size == 0) return true;

		if (cache.find(s) != cache.end())
			return cache[s];

		for (int i = 1; i <= size; i++){
			if (map[s.substr(0, i)] && wordBreakUtil(s.substr(i, size - i))){
				cache[s] = true;
				return true;
			}
		}

		cache[s] = false;
		return false;
	}

	bool wordBreak(string s, vector<string>& wordDict) {
		for (int i = 0; i < wordDict.size(); i++)
			map[wordDict[i]] = true;
		return wordBreakUtil(s);
	}
};