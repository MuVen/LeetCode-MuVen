/*
Given a string s and a non-empty string p, find all the start indices of p's 
anagrams in s.

Strings consists of lowercase English letters only and the length of both 
strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/

//solution
class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		vector<int> result;
		int freqp[26] = { 0 };
		int freqs[26] = { 0 };
		int plen = p.length();
		int slen = s.length();
        if (plen > slen)
			return result;
        
		for (int i = 0; p[i] != '\0'; i++){
			freqp[p[i] - 'a']++;
			freqs[s[i] - 'a']++;
		}

		int fp;
		for (fp= 0; fp < 26; fp++){
			if (freqp[fp] != freqs[fp])
				break;
		}
		if (fp >= 26)result.push_back(0);


		for (int i = 1; i <= slen - plen; i++){
			freqs[s[i - 1] - 'a']--;
			freqs[s[i + plen - 1] - 'a']++;

			int fp;
			for (fp = 0; fp < 26; fp++){
				if (freqp[fp] != freqs[fp])
					break;
			}
			if (fp >= 26)result.push_back(i);
		}

		return move(result);
	}
};