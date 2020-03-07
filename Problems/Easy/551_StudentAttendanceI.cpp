/*
You are given a string representing an attendance record for a student. 
The record only contains the following three characters:
'A' : Absent.
'L' : Late.
'P' : Present.
A student could be rewarded if his attendance record doesn't contain more 
than one 'A' (absent) or more than two continuous 'L' (late).

You need to return whether the student could be rewarded according to his attendance record.

Example 1:
Input: "PPALLP"
Output: True
Example 2:
Input: "PPALLL"
Output: False
*/

//solution
class Solution {
public:
    bool checkRecord(string s) {
        int AC = 0;
        int LC = 0;
        for(int i = 0; s[i] != '\0'; i++){
            if(s[i] == 'A')AC++;
            if(AC > 1)return false;
            if(s[i] == 'L')LC++;
            else if(s[i] != 'L' && LC != 0) LC = 0;
            if(LC > 2)return false;
        }
        return true;
    }
};