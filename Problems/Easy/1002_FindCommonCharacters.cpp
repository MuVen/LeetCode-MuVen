/*
Given an array A of strings made only from lowercase letters, 
return a list of all characters that show up in all strings within the list
 (including duplicates).  For example, if a character occurs 3 times in all 
 strings but not 4 times, you need to include that character three times in the final answer.

You may return the answer in any order.

 

Example 1:

Input: ["bella","label","roller"]
Output: ["e","l","l"]
Example 2:

Input: ["cool","lock","cook"]
Output: ["c","o"]
 

Note:

1 <= A.length <= 100
1 <= A[i].length <= 100
A[i][j] is a lowercase letter
*/

//solution
#define MIN(a,b) ((a)>(b)?(b):(a))

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        string stra[] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
        
        int freq[26];
        for(int i = 0; i < 26; i++){
            freq[i] = INT_MAX;
        }
        int afreq[26] = {0};
        int size = A.size()-1;
        
        for(int i = 0; i < A.size(); i++){
            int lfreq[26] = {0};
            string s = A[i];
            for(int j = 0; s[j] != '\0'; j++){
                int index = s[j]-'a';
                afreq[index] = i;
                lfreq[index]++;
            }
            for(int i = 0; i < 26; i++)
                freq[i] = MIN(freq[i], lfreq[i]);
        }
        
        vector<string> res;
        for(int i = 0; i < 26; i++){
            if(afreq[i] == size){
                int val = freq[i];
                while(val--){
                    res.push_back(stra[i]);
                }
            }
        }
        
        return res;
    }
};