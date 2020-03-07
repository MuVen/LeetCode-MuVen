/*
Implement strStr().

Return the index of the first occurrence of needle in haystack,
 or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Clarification:

What should we return when needle is an empty string? 
This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is 
an empty string. This is consistent to C's strstr() and Java's indexOf().
*/

//solution
class Solution {
public:
    
    vector<int> KMPProcess(string pattern){
        int n = pattern.size();
        vector<int> lps(n,0);
        for(int i = 1, len = 0; i < n;){
            if(pattern[i] == pattern[len]){
                lps[i++] = ++len;
            }else if(len){
                len = lps[len-1];
            }else{
                lps[i++] = 0;
            }
        }
        return lps;
    }
    
    int KMP(string main, string pattern){
        int m = main.size();
        int n = pattern.size();
        if(!n)
            return 0;
        
        vector<int> lps = KMPProcess(pattern);
        for(int i = 0, j = 0; i < m; ){
            if(main[i] == pattern[j]){
                i++, j++;
            }
            if(j == n){
                return i - j;
            }
            if(i < m && main[i] != pattern[j]){
                j ? j = lps[j-1] : i++;
            }
        }
        
        return -1;
    }
    
    int strStr(string haystack, string needle) {
        return KMP(haystack, needle);
    }
};