/*
Given two strings s and t , write a function to determine if t is an 
anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your 
solution to such case?
*/

//solution
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;
        
        int freq[26]={0};
        for(int i = 0; s[i] != '\0'; i++){
            freq[s[i]-'a']++;
            freq[t[i]-'a']--;
        }
        
        
        for(int i = 0; i < 26; i++){
            if(freq[i] != 0)
                return false;
        }
            
        return true;
    }
};