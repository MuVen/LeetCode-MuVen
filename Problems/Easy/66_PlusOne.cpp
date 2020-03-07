/*
Given a non-empty array of digits representing a non-negative integer,
 plus one to the integer.

The digits are stored such that the most significant digit is at the 
head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero,
 except the number 0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Example 2:

Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
*/

//solution
class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		if (digits.size() == 0)
			return vector<int>{};

		vector<int> result;
		int carry = 1;
		for (int i = digits.size() - 1; i >= 0; i--){
			int val = digits[i] + carry;
			if (val >= 10)
				carry = 1;
			else
				carry = 0;
			val = val % 10;
			result.push_back(val);
		}
		if (carry)
			result.push_back(1);

		reverse(result.begin(), result.end());
		return move(result);
	}
};