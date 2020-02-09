/*
Given two words (beginWord and endWord), and a dictionary's word list, 
find all shortest transformation sequence(s) from beginWord to endWord, 
such that:

Only one letter can be changed at a time
Each transformed word must exist in the word list. Note that beginWord 
is not a transformed word.

Note:

Return an empty list if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output:
[
  ["hit","hot","dot","dog","cog"],
  ["hit","hot","lot","log","cog"]
]
Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: []

Explanation: The endWord "cog" is not in wordList, therefore no possible 
transformation.
*/

//solution
class Solution{
public:
	vector<string> addWord(string word, unordered_set<string>& wordlist){
		vector<string> res;
		for (int i = 0; i<word.size(); i++){
			char s = word[i];
			for (char c = 'a'; c <= 'z'; c++){
				word[i] = c;
				if (wordlist.count(word)) res.push_back(word);
			}
			word[i] = s;
		}
		return res;
	}

	vector<vector<string>> findLadders(string beginWord, string endWord, 
	vector<string>& wordList) {
		vector<vector<string>> res;
		unordered_set<string> visit;
		queue<vector<string>> que;
		unordered_set<string> wordlist(wordList.begin(), wordList.end());
		bool flag = false;
		que.push({beginWord});
		while (!que.empty()){
			int size = que.size();
			for (int i = 0; i < size; i++){
				vector<string> cur = que.front();
				que.pop();
				vector<string> newadd = addWord(cur.back(), wordlist);
				for (int j = 0; j < newadd.size(); j++){
					vector<string> newline(cur.begin(), cur.end());
					newline.push_back(newadd[j]);
					if (newadd[j] == endWord){
						flag = true;
						res.push_back(newline);
					}
					visit.insert(newadd[j]);
					que.push(newline);
				}
			}
			if (flag) 
				break;  //do not BFS further 

			for (auto it = visit.begin(); it != visit.end(); it++) 
				wordlist.erase(*it); //erase visited one 

			visit.clear();
		}
		return res;
	}
};