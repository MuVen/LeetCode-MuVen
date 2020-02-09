/*
Given an array A of 0s and 1s, we may change up to K values from 0 to 1.

Return the length of the longest (contiguous) subarray that contains only 1s. 

Example 1:

Input: A = [1,1,1,0,0,0,1,1,1,1,0], K = 2
Output: 6
Explanation: 
[1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1.  The longest subarray is underlined.

Example 2:

Input: A = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3
Output: 10
Explanation: 
[0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1.  The longest subarray is underlined.
 

Note:

1 <= A.length <= 20000
0 <= K <= A.length
A[i] is 0 or 1 
*/

//solution
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        
/*Take two pointers i and j both starting at 0 and start incrementing j one by one until it is smaller that the array size.
If A[j] == 0, decrement the count of K so that we can keep track of remaining flips we can make.
Keep incrementing the j pointer until all the K flips are made.
If the value of K reaches less than 0 at any point, it means that the given range between i and j has more number of 0s than the number of flips allowed, in that case, increment the starting pointer i to make the range smaller.
If the value excluded from the due to incrementing i is 0, then we can get one more flip for the updated range, i.e., increment K.
In the end, return the final range which gives the maximum range which has all ones and which consumes the maximum number of flips allowed.*/
          int i = 0, j = 0;
          for(;i < A.size(); i++){
              if(A[i] == 0){
                  K--;
              }
              if(K < 0){
                  if(A[j] == 0)
                      K++;
                  j++;
              }
          }
        
        return i - j;
    }
};