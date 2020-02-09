/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

Example:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

//solution
class Solution {
    vector<vector<int>> result;
    vector<int> temp;
    vector<int> arr;
public:
    void combinationUtil(int n, int r, int i, int index){
        if(r == index){
            result.push_back(temp);
            return;
        }
        
        if(i >= n)
            return;
        
        temp.push_back(arr[i]);
        combinationUtil(n, r, i + 1, index + 1);
        temp.pop_back();
        combinationUtil(n, r, i + 1, index);
    }
    
    vector<vector<int>> combine(int n, int k) {
        arr.resize(n, 0);
        for(int i = 0; i < n; i++)
            arr[i] = i+1;
        combinationUtil(n, k, 0, 0);
        return result;
    }
};