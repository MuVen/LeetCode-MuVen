/*
Let's define a function f(s) over a non-empty string s, which calculates the 
frequency of the smallest character in s. For example,
 if s = "dcce" then f(s) = 2 because the smallest character is "c" 
 and its frequency is 2.

Now, given string arrays queries and words, return an integer array answer, 
where each answer[i] is the number of words such that f(queries[i]) < f(W), 
where W is a word in words.

 

Example 1:

Input: queries = ["cbd"], words = ["zaaaz"]
Output: [1]
Explanation: On the first query we have f("cbd") = 1, f("zaaaz") = 3 
so f("cbd") < f("zaaaz").
Example 2:

Input: queries = ["bbb","cc"], words = ["a","aa","aaa","aaaa"]
Output: [1,2]
Explanation: On the first query only f("bbb") < f("aaaa").
 On the second query both f("aaa") and f("aaaa") are both > f("cc").
 

Constraints:

1 <= queries.length <= 2000
1 <= words.length <= 2000
1 <= queries[i].length, words[i].length <= 10
queries[i][j], words[i][j] are English lowercase letters.
*/

//solution
class Solution {
public:
    static inline int frequency(string word){
        int freq[26] = {0};
        for(auto ch : word){
            int index = ch - 'a';
            freq[index]++;
        }
        for(int i = 0; i < 26; i++){
            if(freq[i] != 0)
                return freq[i];
        }
        return 0;
    }
    
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> fwords(words.size(), 0);
        vector<int> fqueries(queries.size(), 0);
        vector<int> cache(11, -1);
        
        for(int i = 0; i < words.size(); i++)
            fwords[i] = frequency(words[i]);
        for(int i = 0; i < queries.size(); i++)
            fqueries[i] = frequency(queries[i]);

        vector<int> result(queries.size(),0);
        for(int i = 0; i < queries.size(); i++){
            int qval = fqueries[i];
            if(cache[qval] == -1){
                int count = 0;
                for(int j = 0; j < words.size(); j++){
                    if(fwords[j] > qval)
                        count++;
                }
                result[i] = count;
                cache[qval] = count;
            }else
                result[i] = cache[qval];
        }

        return result;
    }
};