/*
Given a set of candidate numbers (candidates) (without duplicates) and a target 
number (target), find all unique combinations in candidates where the candidate 
numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
Example 2:

Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
*/

//solution
class Solution {
    vector<int> cand;
    vector<vector<int>> res;
    vector<int> tres;
public:
    void ways(int target, int index){
        if(target < 0 || index < 0)
            return;
        
        if(target == 0){
            res.push_back(tres);
            return;
        }
        
        //consider current element.
        tres.push_back(cand[index]);
        ways(target - cand[index], index);
        tres.pop_back();

        //dont consider current element.
        ways(target, index-1);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        cand = move(candidates);
        ways(target, cand.size()-1);
        return res;    
    }
};