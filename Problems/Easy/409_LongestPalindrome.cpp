/*
Given a string which consists of lowercase or uppercase letters, 
find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
*/

//solution
class Solution {
    unordered_map<char,int> map;
public:
    int longestPalindrome(string s) {
        for(auto ch : s)
            map[ch]++;
        int count = 0;
        //consider all even number alphabets
        //consider all odd alphabets - 1
        //if you have odd number alphabets than add 1
        bool haveodd = false;
        for(auto it = map.begin(); it != map.end(); it++){
            if(it->second % 2 == 0){
                count += it->second;
            }else if(it->second % 2 != 0){
                count += it->second-1;
                haveodd = true;
            }
        }
        
        if(haveodd)
            count += 1;
        
        return count;
    }
};