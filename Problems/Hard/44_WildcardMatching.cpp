/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like ? or *.
Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input:
s = "aa"
p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input:
s = "cb"
p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
Example 4:

Input:
s = "adceb"
p = "*a*b"
Output: true
Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
Example 5:

Input:
s = "acdcb"
p = "a*c?b"
Output: false
*/
class Solution {
	vector<vector<int>> cache;
public:
	bool findMatch(string& str, string& pat, int spos, int ppos){
		if (spos == -1 && ppos == -1)
			return true;
		if (spos < -1 || ppos == -1)
			return false;

		if (cache[spos+1][ppos+1] != -1){
			return cache[spos+1][ppos+1] == 1 ? true : false;
		}

		if (pat[ppos] == '?')
			return cache[spos+1][ppos+1] = findMatch(str, pat, spos - 1, ppos - 1);
		else if (pat[ppos] == '*'){
			// aa & * case; aa 
			// abced & *a*d case;
			if (findMatch(str, pat, spos, ppos - 1))
				return cache[spos+1][ppos+1] = true;
            
            if(spos >= 0 && ppos == 0)
                return true;

			/*
			      aaa
				  a*

				  aaa
				  ?*
				  
				  cases
			*/
			for (int i = spos; i >= 0; i--){
				if (str[i] == pat[ppos - 1] || pat[ppos - 1] == '?' || pat[ppos - 1] == '*'){
					if (findMatch(str, pat, i - 1, ppos - 2))
						return cache[spos+1][ppos+1] = true;
				}
			}
			return cache[spos+1][ppos+1] = false;
		}
		else{
			if (spos < 0)
				return cache[spos+1][ppos+1] = false;
			return cache[spos+1][ppos+1] = str[spos] == pat[ppos] && findMatch(str, pat, spos - 1, ppos - 1);
		}
	}

	bool isMatch(string s, string p) {
		cache.resize(s.length() + 2, vector<int>(p.length()+2, -1));
		return findMatch(s, p, s.length() - 1, p.length() - 1);
	}
};