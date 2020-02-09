/*
Given a collection of numbers that might contain duplicates, 
return all possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/

//solution
class Solution {
    vector<vector<int>> res;
    vector<int> mnums;
public:
    void process(int left, int right, int num){
        if(left == right){
            res.push_back(mnums);
            return;
        }

        for(int i = left; i <= right; i++){
            
            bool flag = false;
            for(int j = left; j < i; j++){
                if(mnums[j] == mnums[i]){
                    flag = true;
                    break;
                }
            }
            if(flag)
                continue;
            
            swap(mnums[left], mnums[i]);
            process(left+1, right, num);
            swap(mnums[left], mnums[i]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        mnums = move(nums);
        process(0, mnums.size()-1, 0);
        return move(res);
    }
};