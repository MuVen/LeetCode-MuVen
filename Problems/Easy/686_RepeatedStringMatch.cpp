/*
Given two strings A and B, find the minimum number of times A has to be 
repeated such that B is a substring of it. If no such solution, return -1.

For example, with A = "abcd" and B = "cdabcdab".

Return 3, because by repeating A three times (“abcdabcdabcd”), 
B is a substring of it; and B is not a substring of A repeated two times ("abcdabcd").

Note:
The length of A and B will be between 1 and 10000.
*/

//solution
class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        if(A.find(B) != string::npos)
            return 1;
        
        string result = A;
        int q = 1;
        for(;result.length() < B.length(); q++){ 
            result += A; 
        }

        if(result.find(B) != string::npos)
            return q;

        result += A;
        if(result.find(B) != string::npos)
            return q+1;

        return -1;
    }
};s