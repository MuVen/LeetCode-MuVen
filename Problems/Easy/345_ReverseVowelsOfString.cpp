/*
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:

Input: "hello"
Output: "holle"
Example 2:

Input: "leetcode"
Output: "leotcede"
Note:
The vowels does not include the letter "y".
*/

//solution
class Solution {
    stack<char> sta;
public:
    string reverseVowels(string s) {
        for(int i = 0; s[i] != '\0'; i++){
            if(s[i] == 'a' || s[i] == 'A' ||
               s[i] == 'e' || s[i] == 'E' ||
               s[i] == 'i' || s[i] == 'I' ||
               s[i] == 'o' || s[i] == 'O' ||
               s[i] == 'u' || s[i] == 'U')
            sta.push(s[i]);
        }
        for(int i = 0; s[i] != '\0'; i++){
            if(s[i] == 'a' || s[i] == 'A' ||
               s[i] == 'e' || s[i] == 'E' ||
               s[i] == 'i' || s[i] == 'I' ||
               s[i] == 'o' || s[i] == 'O' ||
               s[i] == 'u' || s[i] == 'U') {
                s[i] = sta.top();sta.pop();
            }
        }
        return move(s);
    }
};