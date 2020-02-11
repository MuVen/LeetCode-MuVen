/*
1347. Minimum Number of Steps to Make Two Strings Anagram

Given two equal-size strings s and t. In one step you can choose any character of t and replace it with another character.

Return the minimum number of steps to make t an anagram of s.

An Anagram of a string is a string that contains the same characters with a different (or the same) ordering.


Example 1:

Input: s = "bab", t = "aba"
Output: 1
Explanation: Replace the first 'a' in t with b, t = "bba" which is anagram of s.
Example 2:

Input: s = "leetcode", t = "practice"
Output: 5
Explanation: Replace 'p', 'r', 'a', 'i' and 'c' from t with proper characters to make t anagram of s.
Example 3:

Input: s = "anagram", t = "mangaar"
Output: 0
Explanation: "anagram" and "mangaar" are anagrams. 
Example 4:

Input: s = "xxyyzz", t = "xxyyzz"
Output: 0
Example 5:

Input: s = "friend", t = "family"
Output: 4
 

Constraints:

1 <= s.length <= 50000
s.length == t.length
s and t contain lower-case English letters only.
*/

class Solution {
    unordered_map<char, int> map;
public:
    int minSteps(string s, string t) {
		//drop freq of chars in s to hashmap
        for(auto& ch : s)
            map[ch]++;
		//remove those freq of chars in t in hashmap
        for(auto& ch : t)
            map[ch]--;
        
		//count the abs value of char freq present in hashmap
        int count = 0;
        for(auto it = map.begin(); it != map.end(); it++){
            count += abs(it->second);
        }
        
		//return count/2 because 1-a 2-b 1-c are left in hashmap means, 1 b can be replaced with a
		// 1 more b can be replaced with c. so count / 2 modifications are required to make one string
		// anagram of another.
        return count/2;
    }
};