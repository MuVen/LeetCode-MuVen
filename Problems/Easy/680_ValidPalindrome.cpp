/*
Given a non-empty string s, you may delete at most one character.
 Judge whether you can make it a palindrome.

Example 1:
Input: "aba"
Output: True
Example 2:
Input: "abca"
Output: True
Explanation: You could delete the character 'c'.
Note:
The string will only contain lowercase characters a-z. The maximum length of the string is 50000.
*/

//solution
class Solution {
    string str;
public:
    bool validPalindrome2(int start, int end, bool& didDelete){
        if(start > end) return true;
        if(str[start] == str[end])
            return validPalindrome2(start+1, end-1, didDelete);
        
        if(didDelete == false){
            didDelete = true;
            return validPalindrome2(start+1, end, didDelete) ||
                   validPalindrome2(start, end-1, didDelete);
        }else
            return false;
        
        return false;
    }
    
    bool validPalindrome(string s) {
        str = s;
        bool didDelete = false;
        return validPalindrome2(0, s.length()-1, didDelete);
    }
};