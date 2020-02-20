/*
Given two non-negative integers num1 and num2 represented as strings, return the product
of num1 and num2, also represented as a string.

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contain only digits 0-9.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/

/*Elementary school mathematics*/
class Solution {
    string answer;
public:
    void addStrings(string tproduct){
        if(answer.length() == 0){
            answer = move(tproduct);
            return;
        }
        
        int i = answer.length()-1;
        int j = tproduct.length()-1;
        
        string temp;
        int carry = 0;
        while(i >= 0 && j >= 0){
            int val = (answer[i]-'0' + tproduct[j]-'0')+carry;
            carry = val >= 10 ? 1 : 0;
            temp.insert(temp.begin(), (val%10)+'0');
            i--;
            j--;
        }
        
        while(i >= 0){
            int val = answer[i]-'0'+carry;
            carry = val >= 10 ? 1 : 0;
            temp.insert(temp.begin(), (val%10)+'0');
            i--;
        }

        while(j >= 0){
            int val = tproduct[j]-'0'+carry;
            carry = val >= 10 ? 1 : 0;
            temp.insert(temp.begin(), (val%10)+'0');
            j--;
        }

        if(carry > 0)
            temp.insert(temp.begin(), carry+'0');
        
        answer = move(temp);
    }
    
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")
            return "0";

        string bigger = num1 > num2 ? num1 : num2;
        string smaller = num1 > num2 ? num2 : num1;
        string ans = "";
        
        for(int i = smaller.length()-1, j = 0; i >= 0; i--, j++){
            char ch1 = smaller[i];
            int carry = 0;
            string tproduct = "";
            for(int k = bigger.length()-1; k >= 0; k--){
                char ch2 = bigger[k];
                int val = ((ch1-'0') * (ch2-'0')) + carry;
                tproduct.insert(tproduct.begin(), ((val%10) + '0'));
                carry = val / 10;
            }
            if(carry > 0)
                tproduct.insert(tproduct.begin(), carry+'0');
            int tj = j;
            while(tj--){
                tproduct.push_back('0');
            }
            //can improve here. Instead of adding them, can do this add in place.
			//while calculating the product.
            addStrings(move(tproduct));
        }
        
        return answer;
    }
};