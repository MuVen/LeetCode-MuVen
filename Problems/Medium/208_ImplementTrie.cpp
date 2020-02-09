/*
Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.
*/

//solution
class Trie {
    struct tnode{
        tnode* childs[26];
        string value;
    };
    tnode nodes[1000000];
    tnode* root;
    int nindex;
public:
    tnode* getNode(){
        tnode* temp = &nodes[nindex++];
        for(int i = 0; i < 26; i++)
            temp->childs[i] = nullptr;
        return temp;
    }
    
    /** Initialize your data structure here. */
    Trie() {
        nindex = 0;
        root = getNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        tnode* pCrawl = root;
        for(int i = 0; word[i] != '\0'; i++){
            int index = word[i]-'a';
            if(pCrawl->childs[index] == nullptr)
                pCrawl->childs[index] = getNode();
            pCrawl = pCrawl->childs[index];
        }
        pCrawl->value = word;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        tnode* pCrawl = root;
        for(int i = 0; word[i] != '\0'; i++){
            int index = word[i]-'a';
            if(pCrawl->childs[index] == nullptr)
                return false;
            pCrawl = pCrawl->childs[index];
        }
        return (pCrawl->value == word);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        tnode* pCrawl = root;
        for(int i = 0; prefix[i] != '\0'; i++){
            int index = prefix[i]-'a';
            if(pCrawl->childs[index] == nullptr)
                return false;
            pCrawl = pCrawl->childs[index];
        }
        
        if(pCrawl->value == prefix)
            return true;
        
        for(int i = 0; i < 26; i++)
            if(pCrawl->childs[i] != nullptr)
                return true;
        
        return false;        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */