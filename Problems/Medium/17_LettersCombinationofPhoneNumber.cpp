/*
Given a string containing digits from 2-9 inclusive, return all possible letter 
combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given 
below. Note that 1 does not map to any letters.



Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:

Although the above answer is in lexicographical order, your answer could be 
in any order you want.
*/

//solution
class Solution {
	vector<string> alpha; 
	vector<int> numbers;
	vector<string> result;
    unordered_map<int,string> map;
	vector<int> vec;
	int vsize;
public:
    //map numbers to words.
	void init(){
        map[2]="abc";
        map[3]="def";
        map[4]="ghi";
        map[5]="jkl";
        map[6]="mno";
        map[7]="pqrs";
        map[8]="tuv";
        map[9]="wxyz";
	}

	void findString(int index, string temp){
		if (index >= vsize){
			result.push_back(temp);
			return;
		}

		int num = vec[index];
		string s = map[num];
		int slen = temp.length();
		for (int i = 0; s[i] != '\0'; i++){
			findString(index + 1, temp+s[i]);
		}
	}

	vector<string> letterCombinations(string digits) {
		init();
		for (int i = 0; digits[i] != '\0'; i++){
			if (digits[i] >= '2'&&digits[i] <= '9')
				vec.push_back(digits[i] - '0');
		}
		vsize = vec.size();
        if(vsize == 0)
            return vector<string>{};
		findString(0, "");
		return result;
	}
};