/*
Given an integer num, find the closest two integers in absolute difference whose product equals num + 1 or num + 2.

Return the two integers in any order.

 

Example 1:

Input: num = 8
Output: [3,3]
Explanation: For num + 1 = 9, the closest divisors are 3 & 3, for num + 2 = 10, the closest divisors are 2 & 5, hence 3 & 3 is chosen.
Example 2:

Input: num = 123
Output: [5,25]
Example 3:

Input: num = 999
Output: [40,25]
 

Constraints:

1 <= num <= 10^9
*/
class Solution {
    vector<int> res;
    int diff = INT_MAX;
public:
    void findClose(int num){
        int a, b, adiff;
        for(int i = 1; i * i <= num; i++){
            if(num % i == 0){
                a = i;
                b = num / i;
                adiff = a > b ? a - b : b - a;
                if(adiff < diff){
                    diff = adiff;
                    res[0] = a;
                    res[1] = b;
                }
            }
        }
    }
    vector<int> closestDivisors(int num) {
        res.resize(2,0);
        findClose(num+1);
        findClose(num+2);
        return res;
    }
};