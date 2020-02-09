/*
Given a string s. Return all the words vertically in the same order in which they appear in s.
Words are returned as a list of strings, complete with spaces when is necessary.
(Trailing spaces are not allowed).
Each word would be put on only one column and that in one column there will be only one word.

 

Example 1:

Input: s = "HOW ARE YOU"
Output: ["HAY","ORO","WEU"]
Explanation: Each word is printed vertically. 
 "HAY"
 "ORO"
 "WEU"
Example 2:

Input: s = "TO BE OR NOT TO BE"
Output: ["TBONTB","OEROOE","   T"]
Explanation: Trailing spaces is not allowed. 
"TBONTB"
"OEROOE"
"   T"
Example 3:

Input: s = "CONTEST IS COMING"
Output: ["CIC","OSO","N M","T I","E N","S G","T"]
*/

//solution
class Solution {
public:
    bool isAlpha(char ch){
        if(ch >= 'A' && ch <= 'Z')
            return true;
        return false;
    }
    vector<string> printVertically(string str) {
        vector<string> res;
	    vector<string> vec;
        int start = -1, i = 0;
        int maxLen = INT_MIN;
        for (i = 0; str[i] != '\0'; i++) {
            if(isAlpha(str[i]) && start == -1){
                start = i;
            }
            else if (start != -1 && str[i] == ' ') {
                vec.push_back(str.substr(start, i-start));
                maxLen = max(maxLen, i - start);
                start = -1;
            }
        }
        if (start != -1) {
            vec.push_back(str.substr(start, str.length() - start));
            maxLen = max(maxLen, (int)str.length() - start);
        }

        for (int i = 0; i < maxLen; i++) {
            string temp;
            for (int j = 0; j < vec.size(); j++) {
                if (i >= vec[j].length())
                    temp += " ";
                else
                    temp += vec[j][i];
            }
            res.push_back(temp);
        }
        
        for (int i = 0; i < res.size(); i++) {
		    string& t = res[i];
		    while (t[t.size() - 1] == ' ') {
		    	t.erase(t.end()-1);
	    	}
    	}
        
        return res;
    }
};