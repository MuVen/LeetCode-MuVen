/*
Given a non-empty list of words, return the k most frequent elements.

Your answer should be sorted by frequency from highest to lowest. 
If two words have the same frequency, then the word with the lower 
alphabetical order comes first.

Example 1:
Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]
Explanation: "i" and "love" are the two most frequent words.
    Note that "i" comes before "love" due to a lower alphabetical order.
	
Example 2:
Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
Output: ["the", "is", "sunny", "day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
    with the number of occurrence being 4, 3, 2 and 1 respectively.
	
Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Input words contain only lowercase letters.
Follow up:
Try to solve it in O(n log k) time and O(n) extra space.
*/
//solution
class Solution {
	vector<string> wor;
	vector<int> freq;
	unordered_map<string, int> map;
public:
	inline void myswap(int a, int b){
		int temp = freq[a];
		freq[a] = freq[b];
		freq[b] = temp;

		string temps = wor[a];
		wor[a] = wor[b];
		wor[b] = temps;
	}

	int partition(int left, int right){
		int pivot = freq[right];
		int sIndex = left;
		for (int i = left; i < right; i++){
			if (freq[i] > pivot){
				myswap(i, sIndex);
				sIndex++;
			}
			else if (freq[i] == pivot){
				if (wor[i].compare(wor[right]) < 0){
					myswap(i, sIndex);
					sIndex++;
				}
			}
		}

		myswap(sIndex, right);
		return sIndex;
	}

	void qsort(int left, int right){
		if (left < right){
			int wall = partition(left, right);
			qsort(left, wall - 1);
			qsort(wall + 1, right);
		}
	}

	vector<string> topKFrequent(vector<string>& words, int k) {
		for (int i = 0; i < words.size(); i++)
			map[words[i]]++;
		for (auto it = map.begin(); it != map.end(); ++it){
			wor.push_back(it->first);
			freq.push_back(it->second);
		}
		qsort(0, freq.size() - 1);
		vector<string> result;
		result.resize(k);
		for (int i = 0; i < k; i++) {
			result[i] = move(wor[i]);
		}
		return move(result);
	}
};