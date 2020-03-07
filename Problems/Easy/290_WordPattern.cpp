/*
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter
 in pattern and a non-empty word in str.

Example 1:

Input: pattern = "abba", str = "dog cat cat dog"
Output: true
Example 2:

Input:pattern = "abba", str = "dog cat cat fish"
Output: false
Example 3:

Input: pattern = "aaaa", str = "dog cat cat dog"
Output: false
Example 4:

Input: pattern = "abba", str = "dog dog dog dog"
Output: false
Notes:
You may assume pattern contains only lowercase letters, and str contains 
lowercase letters that may be separated by a single space.
*/

//solution
class Solution {
    unordered_map<string, char> scmap;
    unordered_map<char, string> csmap;
public:
    bool wordPattern(string pattern, string str) {
        if(pattern.length() == 0 && str.length() != 0)
            return false;
        
        if(pattern.length() != 0 && str.length() == 0)
            return false;
                
        string temp;
        int j = 0;
        for(int i = 0; str[i] != '\0'; i++){
            if(str[i] != ' ')
                temp += str[i];
            else{
                char ch = pattern[j++];
                if(scmap.find(temp) == scmap.end() &&
                   csmap.find(ch) == csmap.end()){
                    scmap[temp] = ch;
                    csmap[ch] = temp;
                }else{
                    if(scmap[temp] != ch || csmap[ch] != temp)
                        return false;
                }
                temp.clear();
            }
        }
        
        char ch = pattern[j++];
        if(scmap.find(temp) == scmap.end() &&
           csmap.find(ch) == csmap.end()){
            scmap[temp] = ch;
            csmap[ch] = temp;
        }else{
            if(scmap[temp] != ch || csmap[ch] != temp)
                return false;
        }
        
        if(j < pattern.length())
            return false;
        
        return true;
    }
};