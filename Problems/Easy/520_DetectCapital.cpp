/*
Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.
 

Example 1:

Input: "USA"
Output: True
 

Example 2:

Input: "FlaG"
Output: False
 

Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.
*/

//solution
class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.length() <= 1)
            return true;
        bool all_lower = true, all_upper = true;
        for(int i = 1; word[i] != '\0'; i++){
            if(islower(word[i]))
                all_upper = false;
            else
                all_lower = false;
        }
        bool ans = all_lower && isupper(word[0]);
        ans |= all_lower && islower(word[0]);
        ans |= all_upper && isupper(word[0]);
        return ans;
    }
};