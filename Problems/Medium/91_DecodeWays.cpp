/*
A message containing letters from A-Z is being encoded to numbers using the 
following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26

Given a non-empty string containing only digits, determine the total number of 
ways to decode it.

Example 1:
Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).

Example 2:
Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
*/

//solution
class Solution {
    int count = 0;
    unordered_map<string,int> map;
public:
    void numDecodingsUtil(string& s) {
        if(s.length() == 0){
            count++;
            return;
        }

        if(map.find(s) != map.end()){
            count += map[s];
            return;
        }

        int n1 = s[0]-'0';
        if(n1 >= 1 && n1 <= 26){
            string sstr = s.substr(1,s.length());
            int ccount = count;
            numDecodingsUtil(sstr);
            int pcount = count - ccount;
            map[sstr] = pcount;
        }
        
        if(n1 == 0)
            return;

        if(s.length() == 1)
            return;
        
        int n2 = s[1]-'0';
        int val = n1*10+n2;
        if(val >= 1 && val <= 26){
            string sstr = s.substr(2,s.length());
            int ccount = count;
            numDecodingsUtil(sstr);
            int pcount = count - ccount;
            map[sstr] = pcount;
        }
    }
    
    int numDecodings(string s) {
        numDecodingsUtil(s);
        /*for(auto it = map.begin(); it != map.end(); ++it){
            cout<<it->first<<" "<<it->second<<endl;
        }*/
        return count;
    }
};