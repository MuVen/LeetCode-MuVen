/*
Given a paragraph and a list of banned words, return the most frequent word that
 is not in the list of banned words.  It is guaranteed there is at least 
 one word that isn't banned, and that the answer is unique.

Words in the list of banned words are given in lowercase, and free of 
punctuation.  Words in the paragraph are not case sensitive.  
The answer is in lowercase.

 

Example:

Input: 
paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
banned = ["hit"]
Output: "ball"
Explanation: 
"hit" occurs 3 times, but it is a banned word.
"ball" occurs twice (and no other word does), so it is the most frequent
 non-banned word in the paragraph. 
Note that words in the paragraph are not case sensitive,
that punctuation is ignored (even if adjacent to words, such as "ball,"), 
and that "hit" isn't the answer even though it occurs more because it is banned.
 

Note:

1 <= paragraph.length <= 1000.
0 <= banned.length <= 100.
1 <= banned[i].length <= 10.
The answer is unique, and written in lowercase (even if its occurrences in
 paragraph may have uppercase symbols, and even if it is a proper noun.)
paragraph only consists of letters, spaces, or the punctuation symbols !?',;.
There are no hyphens or hyphenated words.
Words only consist of letters, never apostrophes or other punctuation symbols.
*/

//solution
class Solution {
    unordered_map<string, int> map;
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower);
        string temp;
        for(int i = 0; paragraph[i] != '\0'; i++){
            if(paragraph[i]>='a' && paragraph[i]<='z')
                temp += paragraph[i];
            else{
                if(temp.length() > 0){
                    map[temp]++;
                    temp.clear();
                }
            }
        }
        if(temp.length() > 0)
            map[temp]++;
        
        for(int i = 0; i < banned.size(); i++){
            transform(banned[i].begin(), banned[i].end(), banned[i].begin(), ::tolower);
            string b = banned[i];
            auto it = map.find(b);
            if(it != map.end()){
                map.erase(it);
            }
        }
        
        int maxCount = INT_MIN;
        string maxString;
        for(auto it = map.begin(); it != map.end(); it++){
            if(it->second > maxCount){
                maxCount = it->second;
                maxString = it->first;
            }
        }
        
        return maxString;
    }
};