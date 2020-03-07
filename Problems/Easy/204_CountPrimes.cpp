/*
Count the number of prime numbers less than a non-negative number, n.

Example:

Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
*/

//solution
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime;
        prime.resize(n, true);
        for(int i = 2; i * i < n; i++){
            if(prime[i] == true){
                for(int j = i*i; j < n ; j += i){
                    prime[j] = false;
                }
            }
        }
        int count = 0;
        for(int i = 2; i < n; i++){
            if(prime[i] == true)
                count++;
        }
        return count;
    }
};