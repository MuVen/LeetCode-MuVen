/*
Implement pow(x, n), which calculates x raised to the power n (xn).

Example 1:

Input: 2.00000, 10
Output: 1024.00000
Example 2:

Input: 2.10000, 3
Output: 9.26100
Example 3:

Input: 2.00000, -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
Note:

-100.0 < x < 100.0
n is a 32-bit signed integer, within the range [−231, 231 − 1]
*/

//solution
#define abs(a,b) ((a)>(b)?(a-b):(b-a))
class Solution {
public:
    double myPowUtil(double x, int n){
        if(n == 0)
             return 1;
        
        double val = myPowUtil(x, n/2);
        int eoro = n%2;
        if(eoro == 0)
            return val * val;
        return val*val*x;
    }
    
    double myPow(double x, int n) {
        if(n < 0 && n != INT_MIN)
            return (double)1.0/myPowUtil(x, n*-1);
        else if(n < 0 && n == INT_MIN)
            return (double)1.0/(x*myPowUtil(x, INT_MAX));
        return myPowUtil(x, n);
    }
};