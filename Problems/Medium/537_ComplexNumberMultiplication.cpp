/*
Given two strings representing two complex numbers.

You need to return a string representing their multiplication. 
Note i2 = -1 according to the definition.

Example 1:
Input: "1+1i", "1+1i"
Output: "0+2i"
Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, 
and you need convert it to the form of 0+2i.

Example 2:
Input: "1+-1i", "1+-1i"
Output: "0+-2i"
Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i,
 and you need convert it to the form of 0+-2i.
Note:

The input strings will not have extra blank.
The input strings will be given in the form of a+bi, 
where the integer a and b will both belong to the range of [-100, 100].
 And the output should be also in this form.
*/

//solution
class Solution {
public:
	void getNumber(string& a, int& no1, int& no2){
		string n1, n2;
		int len = a.length();
		bool isnegative = false;
		bool didbreak = false;
		int i;
		for (i = 0; a[i] != '\0'; i++){
			if (a[i] == '-'){
				isnegative = true;
				continue;
			}
			if (a[i] == '+'){
				a = a.substr(i + 1, len);
				didbreak = true;
				break;
			}
			n1 += a[i];
		}
		no1 = atoi(n1.c_str());
		no1 = isnegative ? no1*-1 : no1;
		if (didbreak == false){
			no2 = 0;
			return;
		}

		isnegative = false;
		for (i = 0; a[i] != '\0'; i++){
			if (a[i] == '-'){
				isnegative = true;
				continue;
			}
			if (a[i] == 'i'){
				break;
			}
			n2 += a[i];
		}

		no2 = atoi(n2.c_str());
		no2 = isnegative ? no2*-1 : no2;
	}

	string complexNumberMultiply(string a, string b) {
		int na1, na2;
		getNumber(a, na1, na2);
		int nb1, nb2;
		getNumber(b, nb1, nb2);

		int real = (na1*nb1) + (na2*nb2*-1);
		int complex = (na1*nb2) + (na2*nb1);
		string result = to_string(real) + "+" + to_string(complex)+"i";
		return result;
	}
};