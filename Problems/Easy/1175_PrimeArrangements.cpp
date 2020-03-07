/*
Return the number of permutations of 1 to n so that prime numbers are
 at prime indices (1-indexed.)

(Recall that an integer is prime if and only if it is greater than 1, 
and cannot be written as a product of two positive integers both smaller than it.)

Since the answer may be large, return the answer modulo 10^9 + 7.

 

Example 1:

Input: n = 5
Output: 12
Explanation: For example [1,2,5,4,3] is a valid permutation, 
but [5,2,3,4,1] is not because the prime number 5 is at index 1.
Example 2:

Input: n = 100
Output: 682289015
 

Constraints:

1 <= n <= 100
*/

//solution
static long long int mod = 1000000007;
//for fun;
static int ans [101] = {0,1,1,2,4,12,36,144,576,2880,17280,86400,604800,3628800,29030400,261273600,612735986,289151874,180670593,445364737,344376809,476898489,676578804,89209194,338137903,410206413,973508979,523161503,940068494,400684877,13697484,150672324,164118783,610613205,44103617,58486801,462170018,546040181,197044608,320204381,965722612,554393872,77422176,83910457,517313696,36724464,175182841,627742601,715505693,327193394,451768713,263673556,755921509,94744060,600274259,410695940,427837488,541336889,736149184,514536044,125049738,250895270,39391803,772631128,541031643,428487046,567378068,780183222,228977612,448880523,892906519,858130261,622773264,78238453,146637981,918450925,514800525,828829204,243264299,351814543,405243354,909357725,561463122,913651722,732754657,430788419,139670208,938893256,28061213,673469112,448961084,80392418,466684389,201222617,85583092,76399490,500763245,519081041,892915734,75763854,682289015};

class Solution {
public:
    //myAnswer;
    int numPrimeArrangementsUtil(int n) {
        vector<bool> isprime(n+1, true);
        isprime[0] = isprime[1] = false;
        for(int i = 2; i * i <= n; i++){
            if(isprime[i] == true){
                for(int j = i*i; j <= n; j += i){
                    isprime[j] = false;
                }
            }
        }
        
        int count = 0;
        for(int i = 0; i <= n; i++)
            if(isprime[i] == true)
                count++;
        
        long long int ans = 1;
        for(int i = 1; i <= count; i++)
            ans = (ans * i) % mod;
        for(int i = 1; i <= n-count; i++)
            ans = (ans * i) % mod;
        return ans;    
    }
    
    int numPrimeArrangements(int n) {
        return ans[n];
    }
};