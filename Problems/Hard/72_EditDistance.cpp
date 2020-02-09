/*
Given two words word1 and word2, find the minimum number of operations 
required to convert word1 to word2.

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
*/

//solution
class Solution {
    string str1, str2;
    vector<vector<int>> cache;
public:

    int minDistanceUtil(int len1, int len2){
        if(len1 == 0)
            return len2;
        if(len2 == 0)
            return len1;
        
        if(str1[len1-1] == str2[len2-1])
            return minDistanceUtil(len1-1, len2-1);
        
        if(cache[len1][len2] != -1)
            return cache[len1][len2];
        
        int v1 = minDistanceUtil(len1-1, len2-1);//replace
        int v2 = minDistanceUtil(len1-1, len2);//insert
        int v3 = minDistanceUtil(len1, len2-1);//delete
            
        return cache[len1][len2] = (min(min(v1, v2), v3))+1;
    }
    
    int minDistance(string word1, string word2) {
        str1 = move(word1);
        str2 = move(word2);
        cache.resize(str1.length()+1, vector<int>(str2.length()+1, -1));
        return minDistanceUtil(str1.length(), str2.length());
    }
};