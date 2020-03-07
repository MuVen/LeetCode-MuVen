/*
Given an integer n. No-Zero integer is a positive integer which doesn't 
contain any 0 in its decimal representation.

Return a list of two integers [A, B] where:

A and B are No-Zero integers.
A + B = n
It's guarateed that there is at least one valid solution.
 If there are many valid solutions you can return any of them.

 

Example 1:

Input: n = 2
Output: [1,1]
Explanation: A = 1, B = 1. A + B = n and both A and B don't 
contain any 0 in their decimal representation.
Example 2:

Input: n = 11
Output: [2,9]
Example 3:

Input: n = 10000
Output: [1,9999]
Example 4:

Input: n = 69
Output: [1,68]
Example 5:

Input: n = 1010
Output: [11,999]
 

Constraints:

2 <= n <= 10^4
*/

//solution
class Solution {
public:
   
    vector<int> getNoZeroIntegers(int n) {
        string n1 = to_string(n-1);
        string n2 = to_string(1);
        
        int in1 = n - 1, in2 = 1;

        
        while(1){
            if(n1.find('0') == string::npos && n2.find('0') == string::npos)
                return {in1, in2};
            
            in1--;
            in2++;
            
            n1 = to_string(in1);
            n2 = to_string(in2);
        }
        
        return {0,0};   
    }
};