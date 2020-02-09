/*
The set [1,2,3,...,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the 
following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note:

Given n will be between 1 and 9 inclusive.
Given k will be between 1 and n! inclusive.
Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"
*/

//solution
class Solution {
    
public:
    string getPermutation(int n, int k) {
        vector<int> fact(n+1, 1);
        vector<char> chars(n);

        for(int i = 1; i <= n; i++){
            fact[i] = fact[i-1] * i;
            chars[i-1] = i+'0';
        }
        
        
        k--;
        string ans;
        for(int i = 1; i <= n; i++){
            int index = k / fact[n-i];
            ans += chars[index];
            cout<<ans<<endl;
            vector<char>::iterator it=chars.begin()+index;
            chars.erase(it);
            k -= index*fact[n-i];
        }

        return ans;
    }
};