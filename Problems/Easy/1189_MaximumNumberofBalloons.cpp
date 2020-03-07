/*
Given a string text, you want to use the characters of text to form as many
 instances of the word "balloon" as possible.

You can use each character in text at most once. 
Return the maximum number of instances that can be formed.

 

Example 1:



Input: text = "nlaebolko"
Output: 1
Example 2:



Input: text = "loonbalxballpoon"
Output: 2
Example 3:

Input: text = "leetcode"
Output: 0
 

Constraints:

1 <= text.length <= 10^4
text consists of lower case English letters only.
*/

//solution
class Solution {
public:
    int maxNumberOfBalloons(string text) {
       int freq[26]={0};
       for(char ch : text){
           int index = ch - 'a';
           freq[index]++;
       }
       
       string name = "balloon";
       int count = 0;
       while(1){
           for(int i = 0; name[i] != '\0'; i++){
                int index = name[i]-'a';
                if(freq[index] == 0)
                    return count;
                freq[index]--;
            }
           count++;
       }
       return count;
    }
};