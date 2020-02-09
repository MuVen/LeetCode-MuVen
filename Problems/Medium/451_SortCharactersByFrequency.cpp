/*
Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
*/

//solution
typedef pair<char, int> mypair;

class Solution {
public:
	string frequencySort(string s) {
		unordered_map<char, int> map;
		for (int i = 0; s[i] != '\0'; i++)
			map[s[i]]++;
		vector<mypair> vec;
		copy(map.begin(), map.end(), back_inserter(vec));
		sort(vec.begin(), vec.end(), [](const mypair& p1, const mypair& p2){
			if (p1.second > p2.second)
				return true;
			return false;
		});
		string ans;
		for (auto it = vec.begin(); it != vec.end(); ++it) {
			mypair mp = *it;
			char ch = mp.first;
 			for (int i = 0; i < mp.second; i++)
				ans += ch;
		}
		return ans;
	}
};