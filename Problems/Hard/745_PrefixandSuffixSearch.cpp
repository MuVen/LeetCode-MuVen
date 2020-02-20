/*
Given many words, words[i] has weight i.

Design a class WordFilter that supports one function, WordFilter.f(String prefix, String suffix).
It will return the word with given prefix and suffix with maximum weight. If no word exists, return -1.

Examples:

Input:
WordFilter(["apple"])
WordFilter.f("a", "e") // returns 0
WordFilter.f("b", "") // returns -1
 

Note:

words has length in range [1, 15000].
For each test case, up to words.length queries WordFilter.f may be made.
words[i] has length in range [1, 10].
prefix, suffix have lengths in range [0, 10].
words[i] and prefix, suffix queries consist of lowercase letters only.
*/

struct TrieNode{
    TrieNode* child[27];
    int weight;
    TrieNode(int w){
        for(int i = 0; i < 27; i++)
            child[i] = nullptr;
        weight = w;
    }
};

/*
Consider the word 'apple'. For each suffix of the word, we could insert that
suffix, followed by '#', followed by the word, all into the trie.

For example, we will insert '#apple', 'e#apple', 'le#apple', 'ple#apple', 'pple#apple', 'apple#apple' into the trie. 

Then for a query like prefix = "ap", suffix = "le", 
we can find it by querying our trie for le#ap.

*/
class WordFilter {
    TrieNode* root = new TrieNode(-1);
public:
    void insert(string word, int weight){
        TrieNode* pCrawl = root;
        for(int i = 0; word[i] != '\0'; i++){
            int index = word[i] - 'a';
            if(word[i] == '#')
                index = 26;
            if(pCrawl->child[index] == nullptr){
                pCrawl->child[index] = new TrieNode(weight);
            }
            //overwrite the weight if its greater than
            //existing weight. we have to return word with
            //greater weight.
            if(weight > pCrawl->child[index]->weight)
                pCrawl->child[index]->weight = weight;
            pCrawl = pCrawl->child[index];
        }
    }
    
    WordFilter(vector<string>& words) {
        for(int weight = 0; weight < words.size(); weight++){
            string word = words[weight];
            string dword = word+"#"+word;
            int size = word.length()+1;
            int i = 1;
            while(size--){
                //cout<<dword<<endl;
                insert(dword, weight);
                dword = dword.substr(i, dword.length());
            }
        }
    }
    
    int findWord(string fword){
        TrieNode* pCrawl = root;
        for(int i = 0; fword[i] != '\0'; i++){
            int index = fword[i] - 'a';
            if(fword[i] == '#')
                index = 26;
            if(pCrawl->child[index] == nullptr){
                return -1;
            }
            pCrawl = pCrawl->child[index];
        }
        return pCrawl->weight;
    }
    
    int f(string prefix, string suffix) {
        string find = suffix+"#"+prefix;
        //cout<<find<<endl;
        return findWord(find);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */