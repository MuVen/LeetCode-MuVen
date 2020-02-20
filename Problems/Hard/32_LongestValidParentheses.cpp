/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Example 1:

Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"
Example 2:

Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"
*/
class Solution {
    stack<int> sta;
public:
    int longestValidParentheses(string s) {
        if(s.length() == 0)
            return 0;
        //same old technique.
        //remove unnecessary parenthesis. instead of marking them with *
        //add space as we need longest parenthesis. we need to seperate them with space
        //which can be used with istringstream to easily split across space and to find
        //out length;
        for(int i = 0; s[i] != '\0'; i++){
            if(s[i] == ')'){
                if(sta.empty()){
                    s[i] = ' ';
                }else if(s[sta.top()] == '('){
                    sta.pop();
                }
            }else{
                sta.push(i);
            }
        }
        while(!sta.empty()){
            s[sta.top()] = ' ';
            sta.pop();
        }
        
        istringstream ss(s);
        string temp;
        int ans = 0;
        while(ss >> temp)
            ans = max(ans, (int)temp.length());
        
        return ans;
    }
};