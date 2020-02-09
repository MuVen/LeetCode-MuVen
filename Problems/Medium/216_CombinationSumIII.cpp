/*
Find all possible combinations of k numbers that add up to a number n, 
given that only numbers from 1 to 9 can be used and each combination should
 be a unique set of numbers.

Note:

All numbers will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]

Example 2:

Input: k = 3, n = 9
Output: [[1,2,6], [1,3,5], [2,3,4]]
*/

//solution
class Solution {
    vector<int> num;
    vector<vector<int>> res;
    vector<int> temp;
    int size;
    int K;
public:
    void process(int index, int count, int sum){
        if(count == K){
            if(sum == 0)
                res.push_back(temp);
            return;
        }
        
        if(index > size)
            return;
       
        temp.push_back(num[index]);
        process(index+1, count+1, sum - num[index]);
        temp.pop_back();
        
        process(index+1, count, sum);
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        size = 9;
        K = k;
        num.resize(10, 0);
        for(int i = 0; i < 10; i++) num[i] = i;
        process(1,0,n);
        return move(res);
    }
};