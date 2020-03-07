/*
Given an integer, return its base 7 string representation.

Example 1:
Input: 100
Output: "202"
Example 2:
Input: -7
Output: "-10"
Note: The input will be in range of [-1e7, 1e7].
*/

//solution
class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0)
            return "0";
        bool isneg = num < 0 ? true : false;
        num = abs(num);
        int d;
        string convert;
        while(num){
            d = num % 7;
            convert += to_string(d);
            num = num / 7;
        }
        reverse(convert.begin(), convert.end());
        convert = isneg ? "-"+convert : convert;
        return convert;
    }
};