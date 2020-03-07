/*
Given a List of words, return the words that can be typed using letters of 
alphabet on only one row's of American keyboard like the image below.

Example:

Input: ["Hello", "Alaska", "Dad", "Peace"]
Output: ["Alaska", "Dad"]
 

Note:

You may use one character in the keyboard more than once.
You may assume the input string will only contain letters of alphabet.
*/

//solution
class Solution {
public:
	vector<string> findWords(vector<string>& words) {
		int row[26] = { 2, 3, 3, 2, 1, 2, 2, 2, 1, 2, 2, 2, 3, 3, 1, 1, 1, 1, 2, 1, 1, 3, 1, 3, 1, 3 };
		vector<string> res;
		vector<string> copy = words;
		for (int i = 0; i < words.size(); i++){
			string s = words[i];
            cout<<s<<" ";
			if (s.length() == 0)
				continue;

			if (s[0] >= 'A'&&s[0] <= 'Z')
				s[0] += 32;
			int srow = row[s[0] - 'a'];
			int j;
			for (j = 1; s[j] != '\0'; j++){
				if (s[j] >= 'A'&&s[j] <= 'Z')
					s[j] += 32;
				if (row[s[j]-'a'] != srow)
					break;
			}
			if (s[j] == '\0')
				res.push_back(copy[i]);
		}
		return move(res);
	}
};