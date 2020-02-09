/*
Given two words (beginWord and endWord), and a dictionary's word list,
 find the length of shortest transformation sequence from beginWord to endWord,
 such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a 
transformed word.
Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.

Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: 0

Explanation: The endWord "cog" is not in wordList, therefore no possible 
transformation.
*/

//solution
struct wordlen{
	int len;
	string word;
	wordlen(int l, string w) :len(l), word(w){}
};

class Solution {
	queue<wordlen> que;
public:
	bool isAdjacent(string& s1, string& s2){
		int l1 = s1.length();
		int l2 = s2.length();
		if (l1 != l2)return false;
		int count = 0;
		for (int i = 0; i < l1; i++){
			if (s1[i] != s2[i])
				count++;
			if (count > 1) return false;
		}
		return (count == 1);
	}

	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		vector<bool> visited;
		visited.resize(wordList.size(), false);

		que.push(wordlen(1, beginWord));
		while (!que.empty()){
			wordlen w = que.front();
			que.pop();
			for (int i = 0; i < wordList.size(); i++){
				string &tstr = wordList[i];
				if (visited[i] == false && isAdjacent(w.word, tstr)){
					if (tstr == endWord)
						return w.len + 1;
					que.push(wordlen(w.len+1, tstr));
					visited[i] = true;
				}
			}
		}
		return 0;
	}
};