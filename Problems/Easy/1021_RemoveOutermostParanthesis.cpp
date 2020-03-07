/*
A valid parentheses string is either empty (""), "(" + A + ")", or A + B, 
where A and B are valid parentheses strings, and + represents string 
concatenation.  For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.

A valid parentheses string S is primitive if it is nonempty, and there does not
 exist a way to split it into S = A+B, with A and B nonempty valid parentheses strings.

Given a valid parentheses string S, consider its primitive decomposition:
 S = P_1 + P_2 + ... + P_k, where P_i are primitive valid parentheses strings.

Return S after removing the outermost parentheses of every primitive string 
in the primitive decomposition of S.

 

Example 1:

Input: "(()())(())"
Output: "()()()"
Explanation: 
The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
After removing outer parentheses of each part, this is "()()" + "()" = "()()()".
Example 2:

Input: "(()())(())(()(()))"
Output: "()()()()(())"
Explanation: 
The input string is "(()())(())(()(()))", with primitive decomposition 
"(()())" + "(())" + "(()(()))".
After removing outer parentheses of each part, this is 
"()()" + "()" + "()(())" = "()()()()(())".
Example 3:

Input: "()()"
Output: ""
Explanation: 
The input string is "()()", with primitive decomposition "()" + "()".
After removing outer parentheses of each part, this is "" + "" = "".
 

Note:

S.length <= 10000
S[i] is "(" or ")"
S is a valid parentheses string
*/

//solution
class Solution {
public:
    string removeOuterParentheses(string S) {
        string ans;
        int open = 0, close = 0, pos = 0;
        for(int i = 0; i < S.length(); i++){
            if(S[i] == '(')open++;
            else if(S[i] == ')')close++;
            
            if(open == close){
                string sub = S.substr(pos, i-pos+1);
                string pans = sub.substr(1, sub.length()-2);
                ans += pans;
                pos = i+1;
                open = close = 0;
            }
        }
        return ans;
    }
};