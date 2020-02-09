/*
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string 
containing only letters a-z or .. A . means it can represent any one letter.

Example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.
*/

//solution
struct trie{
	trie* nodes[26];
	bool endofword;
};
trie tnodes[100000];
int tindex = 0;
trie* getNode(){
	trie* temp = &tnodes[tindex++];
	for (int i = 0; i < 26; i++)
		temp->nodes[i] = nullptr;
	temp->endofword = false;
	return temp;
}
trie* root = nullptr;

class WordDictionary {
public:
	/** Initialize your data structure here. */
	WordDictionary() {
		tindex = 0;
		root = getNode();
		cout << "null,";
	}

	/** Adds a word into the data structure. */
	void addWord(string word) {
		trie* pCrawl = root;
		for (auto ch : word){
			int index = ch - 'a';
			if (pCrawl->nodes[index] == nullptr){
				pCrawl->nodes[index] = getNode();
			}
			pCrawl = pCrawl->nodes[index];
		}
		pCrawl->endofword = true;
		cout << "null,";
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool reSearch(trie* croot, string word){
		trie*pCrawl = croot;
		for (int k = 0; word[k] != '\0'; k++){
			char ch = word[k];
			if (ch == '.'){
				//have 26 possibilites;
				for (int i = 0; i < 26; i++){
					if (pCrawl->nodes[i] != nullptr){
						if (reSearch(pCrawl->nodes[i], word.substr(k + 1)))
							return true;
					}
				}
				return false;
			}
			else{
				int index = ch - 'a';
				if (pCrawl->nodes[index] == nullptr)
					return false;
				pCrawl = pCrawl->nodes[index];
			}
		}

		return pCrawl->endofword;
	}

	bool search(string word) {
		return reSearch(root, word);
	}
};

/**
* Your WordDictionary object will be instantiated and called as such:
* WordDictionary* obj = new WordDictionary();
* obj->addWord(word);
* bool param_2 = obj->search(word);
*/
