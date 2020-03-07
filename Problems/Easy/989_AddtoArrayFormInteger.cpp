/*
For a non-negative integer X, the array-form of X is an array of its 
digits in left to right order.  For example, if X = 1231, then the array form is [1,2,3,1].

Given the array-form A of a non-negative integer X, return the array-form
 of the integer X+K.

 

Example 1:

Input: A = [1,2,0,0], K = 34
Output: [1,2,3,4]
Explanation: 1200 + 34 = 1234
Example 2:

Input: A = [2,7,4], K = 181
Output: [4,5,5]
Explanation: 274 + 181 = 455
Example 3:

Input: A = [2,1,5], K = 806
Output: [1,0,2,1]
Explanation: 215 + 806 = 1021
Example 4:

Input: A = [9,9,9,9,9,9,9,9,9,9], K = 1
Output: [1,0,0,0,0,0,0,0,0,0,0]
Explanation: 9999999999 + 1 = 10000000000
 

Note：

1 <= A.length <= 10000
0 <= A[i] <= 9
0 <= K <= 10000
If A.length > 1, then A[0] != 0
*/

//solution
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        if(K == 0)
            return A;
        
        int CK = K;
        int count = 0;
        while(CK){
            count++;
            CK = CK / 10;
        }
        int ms = max(count, (int)A.size()) + 1;
        vector<int> res;
        res.resize(ms, 0);
        
        int index = ms - 1;
        int carry = 0;
        int digit = 0;
        for(int i = index, j = A.size()-1; i>=0; i--, j--){
            digit = K % 10;
            int val = digit + carry;
            if(j >= 0)
                val += A[j];
            carry = val >= 10 ? 1 : 0;
            res[index--] = val % 10;
            K = K / 10;
        }
        
        while(res[0] == 0)
            res.erase(res.begin());
        return res;
    }
};