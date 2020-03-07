#include <iostream>
#include <wchar.h>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <sstream>

using namespace std;
typedef pair<int, int> mypair;

class StreamAnalyzer {
	struct trie {
		trie* childs[26];
		bool isendofword;
		string word;
		trie() {
			for (int i = 0; i < 26; i++)
				childs[i] = nullptr;
			isendofword = false;
			word = "";
		}
	};
	trie* root = nullptr;
	vector<trie*> mactivenodes;
	vector<trie*> cactivenodes;
	void insert(string word) {
		trie* pCrawl = root;
		for (int i = 0; word[i] != '\0'; i++) {
			int index = word[i] - 'a';
			if (pCrawl->childs[index] == nullptr) {
				pCrawl->childs[index] = new trie();
			}
			pCrawl = pCrawl->childs[index];
		}
		pCrawl->word = word;
		pCrawl->isendofword = true;
	}
public:
	StreamAnalyzer(vector<string> dictionary) {
		root = new trie();
		for (auto& s : dictionary)
			insert(s);
	}
	vector<string> process(char s) {
		vector<string> res;
		int index = s - 'a';
		cactivenodes.clear();
		while (true) {
			auto tnode = mactivenodes.back(); mactivenodes.pop_back();
			if (tnode->childs[index]) {
				if (tnode->childs[index]->isendofword) {
					res.push_back(tnode->word);
				}
				cativenodes.push_back(tnode->childs[index]);
			}
			if (mactivenodes.size() == 0)break;
		}
		mactivenodes = move(cactivenodes);
		if (root->childs[index] != nullptr) {
			mactivenodes.push_back(root->childs[index]; // [d] => [d, o]
		}
		return res;
	}
};

int main() {
	StreamAnalyzer sa({ "dog","cat","at" });
	sa.process('d');
	sa.process('o');
	sa.process('g');
	sa.process('c');
	sa.process('a');
	sa.process('t');
}
