/*
Count the number of segments in a string, where a segment is defined to be a 
contiguous sequence of non-space characters.

Please note that the string does not contain any non-printable characters.

Example:

Input: "Hello, my name is John"
Output: 5
*/

//solution
class Solution {
public:
    int countSegments(string s) {
        istringstream str(s);
        int count = 0;
        string temp;
        while(str >> temp){
            count++;
        }
        return count;
    }
};