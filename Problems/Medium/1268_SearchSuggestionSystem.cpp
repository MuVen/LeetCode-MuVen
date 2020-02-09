/*
Given an array of strings products and a string searchWord.
 We want to design a system that suggests at most three product names from 
 products after each character of searchWord is typed. Suggested products should
 have common prefix with the searchWord. If there are more than three products 
 with a common prefix return the three lexicographically minimums products.

Return list of lists of the suggested products after each character of searchWord is typed. 

 

Example 1:

Input: products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
Output: [
["mobile","moneypot","monitor"],
["mobile","moneypot","monitor"],
["mouse","mousepad"],
["mouse","mousepad"],
["mouse","mousepad"]
]
Explanation: products sorted lexicographically = ["mobile","moneypot","monitor","mouse","mousepad"]
After typing m and mo all products match and we show user ["mobile","moneypot","monitor"]
After typing mou, mous and mouse the system suggests ["mouse","mousepad"]
Example 2:

Input: products = ["havana"], searchWord = "havana"
Output: [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]
Example 3:

Input: products = ["bags","baggage","banner","box","cloths"], searchWord = "bags"
Output: [["baggage","bags","banner"],["baggage","bags","banner"],["baggage","bags"],["bags"]]
Example 4:

Input: products = ["havana"], searchWord = "tatiana"
Output: [[],[],[],[],[],[],[]]
 

Constraints:

1 <= products.length <= 1000
There are no repeated elements in products.
1 <= Σ products[i].length <= 2 * 10^4
All characters of products[i] are lower-case English letters.
1 <= searchWord.length <= 1000
All characters of searchWord are lower-case English letters.
*/

//solution
class Solution {
    struct trie{
        trie* childs[26];
        string word;
        bool endofword;
    };
    trie* getNode(){
        trie* t = new trie();
        for(int i = 0; i < 26; i++)
            t->childs[i] = nullptr;
        t->endofword = false;
        return t;
    }
    trie* root = getNode();
    vector<vector<string>> res;
public:
    void insertString(string s){
        trie* pCrawl = root;
        for(int i = 0; s[i] != '\0'; i++){
            int index = s[i]-'a';
            if(pCrawl->childs[index] == nullptr){
                pCrawl->childs[index] = getNode();
            }
            pCrawl = pCrawl->childs[index];
        }
        pCrawl->endofword = true;
        pCrawl->word = s;
    }
    
    void update(trie* root, int& count, int& rindex){
        if(root == nullptr)
            return;
        
        if(count >= 3)
            return;
        
        if(root->endofword == true && count < 3){
            res[rindex].push_back(root->word);
            count++;
        }
        
        trie* pCrawl = root;
        for(int i = 0; i < 26; i++){
            if(pCrawl->childs[i]){
                update(pCrawl->childs[i], count, rindex);
                if(count >= 3)
                    return;
            }
        }
    }
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        for(int i = 0; i < products.size(); i++){
            string s = products[i];
            insertString(s);
        }
        res.resize(searchWord.size(), vector<string>{});
        for(int i = 0; i < searchWord.length(); i++){
            string se = searchWord.substr(0, i+1);
            trie* pCrawl = root;
            int j;
            for(j = 0; se[j] != '\0'; j++){
                int index = se[j]-'a';
                if(pCrawl->childs[index])
                    pCrawl = pCrawl->childs[index];
                else
                    break;
            }
            if(se[j] != '\0')break;
            int count = 0;
            update(pCrawl, count, i);
        }
        return res;
    }
};