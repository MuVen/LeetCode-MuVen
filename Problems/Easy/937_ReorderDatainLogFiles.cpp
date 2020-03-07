/*
You have an array of logs.  Each log is a space delimited string of words.

For each log, the first word in each log is an alphanumeric identifier.  
Then, either:

Each word after the identifier will consist only of lowercase letters, or;
Each word after the identifier will consist only of digits.
We will call these two varieties of logs letter-logs and digit-logs. 
 It is guaranteed that each log has at least one word after its identifier.

Reorder the logs so that all of the letter-logs come before any digit-log.  
The letter-logs are ordered lexicographically ignoring identifier, with the 
identifier used in case of ties.  The digit-logs should be put in their original order.

Return the final order of the logs.

 

Example 1:

Input: logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
Output: ["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"]
 

Constraints:

0 <= logs.length <= 100
3 <= logs[i].length <= 100
logs[i] is guaranteed to have an identifier, and a word after the identifier.
*/

//solution
class Solution {
public:
	static bool compare(const string& s1, const string& s2) {
		auto p1 = s1.find(" ");
		auto p2 = s2.find(" ");
		string p1c = s1.substr(p1 + 1);
		string p2c = s2.substr(p2 + 1);
		string p1i = s1.substr(0, p1);
		string p2i = s2.substr(0, p2);

		if (p1c > p2c)
			return false;
		else if (p1c < p2c)
			return true;
		return p1i <= p2i;
	}

	vector<string> reorderLogFiles(vector<string>& logs) {
		vector<string> letters;
		vector<int> digits;

		for (int i = 0; i < logs.size(); ++i) {
			auto index = logs[i].find(" ");
			if (isalpha(logs[i][index + 1]))
				letters.push_back(logs[i]);
			else
				digits.push_back(i);
		}

		sort(letters.begin(), letters.end(), compare);

		for (int i = 0; i < digits.size(); ++i)
			letters.push_back(logs[digits[i]]);

		return letters;
	}
};
