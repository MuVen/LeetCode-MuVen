/*
Given a string, you need to reverse the order of characters in each word within
 a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Note: In the string, each word is separated by single space and there will not be any extra space in the string.
*/

//solution
class Solution {
    string output;
    string answer;
public:
    string reverseWords(string s) {
        for(int i = 0; s[i] != '\0'; i++){
            if(s[i] == ' ') {
                reverse(output.begin(), output.end());
                answer += output + " ";
                output.clear();
            }else
                output += s[i];
        }

        reverse(output.begin(), output.end());
        answer += output;
        return move(answer);
    }
};

/*class Solution {
    stack<char> sta;
    string output;
public:
    string reverseWords(string s) {
        for(int i = 0; s[i] != '\0'; i++){
            if(s[i] == ' '){
                while(!sta.empty()){
                    output += sta.top();sta.pop();
                }
                output +=' ';
            }else
                sta.push(s[i]);
        }
        while(!sta.empty()){
            output += sta.top();sta.pop();
        }
        return move(output);
    }
};*/

/*
class Solution {
public:
    string reverseWords(string s) {
        string output;
        for(int i = 0; s[i] != '\0'; i++){
            if(s[i] == ' '){
                string prev = reverseWords(s.substr(i+1, s.length()));
                reverse(output.begin(), output.end());
                return output +' '+prev;
            }
            else
                output += s[i];
        }
        
        reverse(output.begin(), output.end());
        return move(output);
    }
};
*/