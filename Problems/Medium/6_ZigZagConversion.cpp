/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of 
rows like this: (you may want to display this pattern in a fixed font for 
better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion 
given a number of rows:

string convert(string s, int numRows);
Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I
*/

//solution
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        
        unordered_map<int,string> map;
        int i = 0, row = 0;
        bool down = true;
        while(s[i] != '\0'){
            map[row] += s[i];
            if(down == true){
                if(row == numRows-1){
                    down = false;
                }
            }
            if(down == false){
                if(row == 0){
                    down = true;
                }
            }
            
            down == true ? row++ : row--;
            i++;
        }
        
        string result;
        for(int i = 0; i < numRows; i++){
            result += map[i];
        }
        
        return result;
    }
};