/*
Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

//solution
class Solution {
    vector<vector<int>> res;
    vector<int> tnums;
public:
    void permutation(int start, int end){
        if(start == end){
            res.push_back(tnums);
            return;
        }
        for(int i = start; i <= end; i++){
            swap(tnums[i], tnums[start]);
            permutation(start+1, end);
            swap(tnums[i], tnums[start]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size() == 0)
            return vector<vector<int>>{};

        tnums = move(nums);
        permutation(0, tnums.size()-1);
        return res;
    }
};