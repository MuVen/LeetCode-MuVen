/*
Given a string, find the first non-repeating character in it and return it's 
index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.
*/

//solution
#define MIN(a,b) ((a)>(b)?(b):(a))

class Solution {
public:
    int firstUniqChar(string s) {
        int freq[26]={0};
        for(int i = 0; s[i] !='\0'; i++){
            freq[s[i]-'a']++;
        }
        
        for(int i = 0; s[i] !='\0'; i++){
            if(freq[s[i]-'a'] == 1)
                return i;
        }
        
        return -1;
    }
};