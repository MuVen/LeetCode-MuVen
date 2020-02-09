/*
Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the 
square brackets is being repeated exactly k times. Note that k is guaranteed 
to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, 
square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits
 and that digits are only for those repeat numbers, k. For example, there won't 
 be input like 3a or 2[4].

Examples:

s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
*/

//solution
class Solution {
public:
	bool isNumeric(char ch) {
		return ch >= '0' && ch <= '9';
	}
	bool isAlpha(char ch) {
		return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
	}
	string decodeString(string s) {
		stack<string> ssta;
		stack<int> ista;
		int number = 0;
		for (int i = 0; s[i] != '\0'; i++){
			char ch = s[i];
			if (isAlpha(ch)){
				string t;
				t = t + ch;
				ssta.push(t);
			}
			else if (isNumeric(ch)){
				number = number * 10 + (ch - '0');
			}
			else if (ch == '['){
				ista.push(number);
				ssta.push("[");
				number = 0;
			}
			else if (ch == ']'){
				string temp;
				while (!ssta.empty() && ssta.top() != "["){
					temp = ssta.top() + temp;
					ssta.pop();
				}
				ssta.pop();

				string rtemp;
				int repeat = ista.top(); ista.pop();
				for (int i = 1; i <= repeat; i++)
					rtemp = rtemp + temp;

				ssta.push(rtemp);
			}
		}

		string ans;
		while (!ssta.empty()){
			ans = ssta.top() + ans;
			ssta.pop();
		}
		return ans;
	}
};