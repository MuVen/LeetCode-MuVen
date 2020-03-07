/*
Given a string and an integer k, you need to reverse the first k characters for 
every 2k characters counting from the start of the string. If there are less 
than k characters left, reverse all of them. If there are less than 2k but 
greater than or equal to k characters, then reverse the first k characters and left the other as original.
Example:
Input: s = "abcdefg", k = 2
Output: "bacdfeg"
Restrictions:
The string consists of lower English letters only.
Length of the given string and k will in the range [1, 10000]
*/

//solution
class Solution {
    string str;
public:
    void reverseStr(int start, int end){
        while(start <= end){
            swap(str[start++], str[end--]);
        }
    }
    
    string reverseStr(string s, int k) {
        str = move(s);
        for(int i = 0; i < str.length(); ){
            int start = i;
            int end =   i + (2*k) -1;
            if(end > str.length()-1)
                end = str.length()-1;
            //end greater than str len;
            //number of elements is end-start+1
            //if nele > k then reverse rend = start + k - 1
            //else rend = end
            int nele = end - start + 1;
            int rend;
            if(nele > k )
                rend = start+k-1;
            else
                rend = end;
            reverseStr(start, rend);
            i = end + 1;
        }
        return str;
    }
};