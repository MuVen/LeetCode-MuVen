/*
Given two non-negative integers num1 and num2 represented as string, 
return the sum of num1 and num2.

Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/

//solution
class Solution {
public:
	string addStrings(string a, string b) {
		int i = a.length() - 1;
		int j = b.length() - 1;
		int carry = 0;
		string ans;
		while (i >= 0 && j >= 0){
			int val = a[i] - '0' + b[j] - '0' + carry;
			if (val >= 10)
				carry = 1;
			else
				carry = 0;
			ans += (val % 10) + '0';
			i--;
			j--;
		}

		while (i >= 0){
			int val = a[i] - '0' + carry;
			if (val >= 10)
				carry = 1;
			else
				carry = 0;
			ans += (val % 10) + '0';
			i--;
		}

		while (j >= 0){
			int val = b[j] - '0' + carry;
			if (val >= 10)
				carry = 1;
			else
				carry = 0;
			ans += (val % 10) + '0';
			j--;
		}

		if (carry == 1)
			ans += '1';

		reverse(ans.begin(), ans.end());
		return ans;
	}
};