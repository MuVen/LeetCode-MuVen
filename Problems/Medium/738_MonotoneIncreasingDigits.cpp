/*
Given a non-negative integer N, find the largest number that is less than 
or equal to N with monotone increasing digits.

(Recall that an integer has monotone increasing digits if and only if each pair of adjacent digits x and y satisfy x <= y.)

Example 1:
Input: N = 10
Output: 9
Example 2:
Input: N = 1234
Output: 1234
Example 3:
Input: N = 332
Output: 299
Note: N is an integer in the range [0, 10^9].
*/

//solution
class Solution {
public:
	int monotoneIncreasingDigits(int N) {
		vector<int> vec;
		while (N){
			int d = N % 10;
			vec.push_back(d);
			N = N / 10;
		}
		reverse(vec.begin(), vec.end());
		int pos = vec.size();
		for (int i = vec.size() - 2; i >= 0; i--){
			if (vec[i] > vec[i + 1]){
				vec[i]--;
				pos = i + 1;
			}
		}

		for (int i = pos; i < vec.size(); i++)
			vec[i] = 9;

		int num = 0;
		for (int i = 0; i < vec.size(); i++){
			num = num * 10 + vec[i];
		}

		return num;
	}
};