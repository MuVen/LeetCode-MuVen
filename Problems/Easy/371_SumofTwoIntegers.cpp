/*
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example 1:

Input: a = 1, b = 2
Output: 3
Example 2:

Input: a = -2, b = 3
Output: 1
*/

//solution
class Solution {
public:
    int getSum(int a, int b) {
        int carry = 0;
        while(b){
            carry = a & b;
            a = a ^ b;
            b = (unsigned int)carry << 1;
        }
        return a;
    }
};