/*
Given a string, find the length of the longest substring without repeating 
characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence 
			 and not a substring.
*/

//solution

#define MAX(a,b) ((a)>(b)?(a):(b))
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int size = s.length();
		if (size == 0)
			return 0;

		int ans = 0;
		unordered_map<char, int> mymap;
        //mymap, count the freq of the character;
        //if the freq of the character is greater than 1,
        //then keep moving i to right and calculate the max width for every iteration.
		for(int i = 0, j = 0; j < size; j++){
            mymap[s[j]]++;
            while(mymap[s[j]] > 1)
                mymap[s[i++]]--;
            ans = max(ans, j - i + 1);
        }

		return ans;
	}
};