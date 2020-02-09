/*

Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.
*/

//solution
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>> map;
        for(int i = 0; i < strs.size(); i++){
            string s = strs[i];
            sort(s.begin(), s.end());
            map[s].push_back(strs[i]);
        }
        
        vector<vector<string>> result;
        for(auto it = map.begin(); it != map.end(); ++it){
            vector<string> s = it->second;
            result.push_back(s);
        }
        return result;
    }
};