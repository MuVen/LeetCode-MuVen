/*
Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like . or *.
Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input:
s = "aa"
p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
Example 3:

Input:
s = "ab"
p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
Example 4:

Input:
s = "aab"
p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".
Example 5:

Input:
s = "mississippi"
p = "mis*is*p*."
Output: false
*/

class Solution {
public:
    bool findMatch(string& str, string& pat, int spos, int ppos){
        //spos and ppos is equal to -1; then its true; pattern matches string
        if(spos == -1 && ppos == -1)
            return true;
        
        //if either of the string reaches end and another string doesnt reach then its false.
        if(spos < -1 || ppos == -1)
            return false;
        
        //if pattern is . then check for rest of the chars in pattern and string
        if(pat[ppos] == '.')
            return findMatch(str, pat, spos-1, ppos-1);
        else if(pat[ppos] == '*'){
            //match zero element; "aab" "c*a*b" here c* has appeared zero times;
            //go -2 chars in the pattern pos;
            if(findMatch(str, pat, spos, ppos - 2))
                return true;
            /*
                   a a a 
                     a *
            */
            //else run each char one by one; try to match aaa to a* or aaa to .*
            for(int i = spos; i >= 0 && (pat[ppos - 1] == '.' || str[i] == pat[ppos - 1]); i--){
                if(findMatch(str, pat, i - 1, ppos - 2))
                    return true;
            }
            return false;
        }else{
            //single character; check if two chars match and check for rest of the chars in pattern and string.
            if(spos < 0)
                return false;
            return (str[spos] == pat[ppos]) && findMatch(str, pat, spos-1, ppos-1);
        }
    }
    
    bool isMatch(string s, string p) {
        return findMatch(s, p, s.length()-1, p.length()-1);
    }
};