/*
Given a 2D board and a list of words from the dictionary, find all words 
in the board.

Each word must be constructed from letters of sequentially adjacent cell, 
where "adjacent" cells are those horizontally or vertically neighboring. 
The same letter cell may not be used more than once in a word.

Example:

Input: 
board = [
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
words = ["oath","pea","eat","rain"]

Output: ["eat","oath"]
 

Note:

All inputs are consist of lowercase letters a-z.
The values of words are distinct.
*/

//solution
struct Trie {
	Trie* childs[26];
	bool isend;
};
Trie nodes[1000000];
int indexT = 0;
Trie* getNode() {
	Trie* temp = &nodes[indexT++];
	temp->isend = false;
	for (int i = 0; i < 26; i++)
		temp->childs[i] = nullptr;
	return temp;
}
Trie* root = nullptr;
void addWord(string& word) {
	Trie* pCrawl = root;
	for (int i = 0; word[i] != '\0'; i++) {
		int index = word[i] - 'a';
		if (pCrawl->childs[index] == nullptr)
			pCrawl->childs[index] = getNode();
		pCrawl = pCrawl->childs[index];
	}
	pCrawl->isend = true;
}
bool hasWord(string& word) {
	Trie* pCrawl = root;
	for (int i = 0; word[i] != '\0'; i++) {
		int index = word[i] - 'a';
		if (pCrawl->childs[index] == nullptr)
			return false;
		pCrawl = pCrawl->childs[index];
	}
	return pCrawl->isend;
}



class Solution {
	vector<vector<char>> cboard;
	unordered_set<string> result;
	int row, col;
public:
	void findAll(int x, int y, string res, Trie* root) {
		if (x < 0 || x >= row || y < 0 || y >= col || cboard[x][y] == '\0')
			return;
		
		//cout << res << endl;
		int index = cboard[x][y] - 'a';
		if (root->childs[index]) {
			root = root->childs[index];

			char temp = cboard[x][y];
			cboard[x][y] = '\0';
			res += temp;

			if (root->isend)
				result.insert(res);

			findAll(x - 1, y, res,root);
			findAll(x + 1, y, res, root);
			findAll(x, y + 1, res, root);
			findAll(x, y - 1, res, root);

			cboard[x][y] = temp;
		}
	}

	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		cboard = move(board);
		row = cboard.size();
		col = cboard[0].size();
		
		root = getNode();
		for (int i = 0; i < words.size(); i++) {
			addWord(words[i]);
		}

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				string temp;
				findAll(i, j, temp, root);
			}
		}

		vector<string> fres;
		for (auto it = result.begin(); it != result.end(); ++it)
			fres.push_back(*it);
		return move(fres);
	}
};