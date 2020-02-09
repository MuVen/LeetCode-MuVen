/*
Given two integers representing the numerator and denominator of a fraction,
 return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

Example 1:

Input: numerator = 1, denominator = 2
Output: "0.5"
Example 2:

Input: numerator = 2, denominator = 1
Output: "2"
Example 3:

Input: numerator = 2, denominator = 3
Output: "0.(6)"
*/

//solutionclass Solution {
    unordered_map<long, int> map;
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0)
            return "0";

        string ans;
        if(numerator < 0 ^ denominator < 0){
            ans += "-";
        }
        
        long int num = labs(numerator);
        long int den = labs(denominator);

        long int r = num % den;
        ans += to_string(num / den);
        if(r == 0)
            return ans;

        ans += ".";
        while(r){
            if(map.find(r) != map.end()){
                ans = ans.insert(map[r], "(");
                ans += ")";
                break;
            }
            
            map[r] = ans.size();
            r *= 10;
            ans += to_string(r/den);
            r %= den;
        }

        return ans;
    }
};