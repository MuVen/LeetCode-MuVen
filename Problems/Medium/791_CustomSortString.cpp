/*
S and T are strings composed of lowercase letters. In S, no letter occurs 
more than once.

S was sorted in some custom order previously. We want to permute the 
characters of T so that they match the order that S was sorted. 
More specifically, if x occurs before y in S, then x should occur before 
y in the returned string.

Return any permutation of T (as a string) that satisfies this property.

Example :
Input: 
S = "cba"
T = "abcd"
Output: "cbad"
Explanation: 
"a", "b", "c" appear in S, so the order of "a", "b", "c" should be "c", "b", and "a". 
Since "d" does not appear in S, it can be at any position in T. "dcba", "cdba",
"cbda" are also valid outputs.
 

Note:

S has length at most 26, and no character is repeated in S.
T has length at most 200.
S and T consist of lowercase letters only.
*/

//solution
class Solution {
public:
	string customSortString(string S, string T) {
		if (S == T)
			return S;

		unordered_map<char, int> map;
		for (int i = 0; T[i] != '\0'; i++)
			map[T[i]]++;

		string s;
		for (int i = 0; S[i] != '\0'; i++) {
			int k = map[S[i]];
			while (k--) {
				s.push_back(S[i]);
			}
			map.erase(S[i]);
		}
		for (auto it = map.begin(); it != map.end(); ++it) {
			int k = map[it->first];
			while (k--)
				s.push_back(it->first);
		}

		return s;
	}
};